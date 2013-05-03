#!/usr/bin/env python
"""
@file    visum_parseZaehlstelle.py
@author  Daniel Krajzewicz
@author  Michael Behrisch
@date    2008-11-30
@version $Id: visum_parseZaehlstelle.py 13811 2013-05-01 20:31:43Z behrisch $


This script reads "Zaehlstellen" from a given VISUM-network
 and projects them onto a given SUMO-network.
The parsed "Zaehlstellen" are written as POIs.

SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
Copyright (C) 2008-2013 DLR (http://www.dlr.de/) and contributors
All rights reserved
"""

import sys, os
from xml.sax import saxutils, make_parser, handler

sys.path.append(os.path.join(os.path.abspath(os.path.dirname(sys.argv[0])), "../../lib"))
import sumonet

if len(sys.argv) < 3:
    print "Usage: " + sys.argv[0] + " <SUMO-net> <VISUM-net> <output>"
    sys.exit()
print "Reading net..."
parser = make_parser()
net = sumonet.NetReader()
parser.setContentHandler(net)
parser.parse(sys.argv[1])

print "Reading VISUM..."
fd = open(sys.argv[2])
fdo = open(sys.argv[3], "w")
fdo.write("<pois>\n")
parsingCounts = False
for line in fd:
	if parsingCounts:
		if line[0]=='*' or line[0]=='$' or line.find(";")<0:
			parsingCounts = False
			continue

		print line
		vals = line.split(";")
		id = vals[0] + ";" + vals[1]
		fromNode = vals[3]
		toNode = vals[4]
		strID = vals[5]
		rest = ";".join(vals[lastKnown+1:]).strip()
		fN = net.getNet()._id2node[fromNode]
		me = None
		for e in fN._outgoing:
			if e._id == strID or e._id == "-" + strID:
				me = e
		if me==None:
			print "Not found " + line
		else:
			l = str(me._id) + "_0"
			p = str(me._length * float(vals[6]))
			fdo.write('   <poi id="' + id + '" type="' + vals[7] + '" lane="' + l + '" pos="' + p + '" color="0,1,0" values="' + rest + '" layer="1"/>\n')

	if line.find("$ZAEHLSTELLE")==0:
		parsingCounts = True
		lastKnown = line.split(";").index("ISTINAUSWAHL")
fdo.write("</pois>\n")

