/****************************************************************************/
/// @file    MFXEditableTable.h
/// @author  Daniel Krajzewicz
/// @date    2004-07-02
/// @version $Id: MFXEditableTable.h 13811 2013-05-01 20:31:43Z behrisch $
///
// missing_desc
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// Copyright (C) 2001-2013 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef MFXEditableTable_h
#define MFXEditableTable_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <fx.h>
#include <set>

struct MFXEditedTableItem {
    FXTableItem* item;
    int row;
    int col;
    bool updateOnly;
};

enum {
    EDITTABLE_NEXTROW     = 0x02000000   /// Allow editing the next row (not all other)
};


class MFXEditableTable : public FXTable {
    FXDECLARE(MFXEditableTable)
public:
    enum {
        ID_LABELEDIT = FXTable::ID_LAST,
        ID_EDITEND,
        ID_NEXTLINE,
        ID_EDITOR,
        ID_TEXT_CHANGED,
        ID_LAST
    };
    MFXEditableTable(FXComposite* p, FXObject* tgt = NULL, FXSelector sel = 0, FXuint opts = 0, FXint x = 0, FXint y = 0, FXint w = 0, FXint h = 0, FXint pl = DEFAULT_MARGIN, FXint pr = DEFAULT_MARGIN, FXint pt = DEFAULT_MARGIN, FXint pb = DEFAULT_MARGIN);
    ~MFXEditableTable();

public:
    long onLeftBtnPress(FXObject* sender, FXSelector sel, void* ptr);
    long onLeftBtnRelease(FXObject* sender, FXSelector sel, void* ptr);
    long onLeftBtnClicked(FXObject* sender, FXSelector sel, void* ptr);

    virtual void editItem(FXTableItem* item, FXint how);
    virtual void editEnd();
    long onEditEnd(FXObject*, FXSelector, void*);
    virtual void editCancel();
    long onEditKeyPress(FXObject*, FXSelector, void* ptr);
    long onKeyRelease(FXObject* sender, FXSelector sel, void* ptr);
    long onEditFocusOut(FXObject*, FXSelector, void*);
//    long onTipTimer(FXObject* sender, FXSelector sel, void* ptr);
    long onRightBtnRelease(FXObject* sender, FXSelector sel, void* ptr);


    long onHScrollerChanged(FXObject* o, FXSelector s, void* d);
    long onVScrollerChanged(FXObject* o, FXSelector s, void* d);
    long onHScrollerDragged(FXObject* o, FXSelector s, void* d);
    long onVScrollerDragged(FXObject* o, FXSelector s, void* d);

    long onAutoScroll(FXObject* o, FXSelector s, void* d);
    long onUngrabbed(FXObject* o, FXSelector s, void* d);
    long onRightBtnPress(FXObject* o, FXSelector s, void* d);
    long onTabKeyPress(FXObject* o, FXSelector s, void* d);
    long onTabKeyRelease(FXObject* o, FXSelector s, void* d);
    long onFocusIn(FXObject* o, FXSelector s, void* d);
    long onFocusOut(FXObject* o, FXSelector s, void* d);
    long onSelectionLost(FXObject* o, FXSelector s, void* d);
    long onSelectionGained(FXObject* o, FXSelector s, void* d);
    long onSelectionRequest(FXObject* o, FXSelector s, void* d);
    long onClipboardLost(FXObject* o, FXSelector s, void* d);
    long onClipboardGained(FXObject* o, FXSelector s, void* d);
    long onClipboardRequest(FXObject* o, FXSelector s, void* d);
    long onDoubleClicked(FXObject* o, FXSelector s, void* d);
    long onTripleClicked(FXObject* o, FXSelector s, void* d);
    long onCommand(FXObject* o, FXSelector s, void* d);
    long onUpdHorzGrid(FXObject* o, FXSelector s, void* d);
    long onUpdVertGrid(FXObject* o, FXSelector s, void* d);
    long onCmdHorzGrid(FXObject* o, FXSelector s, void* d);
    long onCmdVertGrid(FXObject* o, FXSelector s, void* d);
    long onCmdDeleteColumn(FXObject* o, FXSelector s, void* d);
    long onUpdDeleteColumn(FXObject* o, FXSelector s, void* d);
    long onCmdDeleteRow(FXObject* o, FXSelector s, void* d);
    long onUpdDeleteRow(FXObject* o, FXSelector s, void* d);
    long onCmdInsertColumn(FXObject* o, FXSelector s, void* d);
    long onCmdInsertRow(FXObject* o, FXSelector s, void* d);

    long onCmdMoveLeft(FXObject* o, FXSelector s, void* d);
    long onCmdMoveRight(FXObject* o, FXSelector s, void* d);
    long onCmdMoveUp(FXObject* o, FXSelector s, void* d);
    long onCmdMoveDown(FXObject* o, FXSelector s, void* d);
    long onCmdMoveHome(FXObject* o, FXSelector s, void* d);
    long onCmdMoveEnd(FXObject* o, FXSelector s, void* d);
    long onCmdMoveTop(FXObject* o, FXSelector s, void* d);
    long onCmdMoveBottom(FXObject* o, FXSelector s, void* d);
    long onCmdMovePageDown(FXObject* o, FXSelector s, void* d);
    long onCmdMovePageUp(FXObject* o, FXSelector s, void* d);

    long onCmdSelectRowIndex(FXObject* o, FXSelector s, void* d);
    long onCmdSelectColumnIndex(FXObject* o, FXSelector s, void* d);
    long onCmdSelectColumn(FXObject* o, FXSelector s, void* d);
    long onCmdSelectRow(FXObject* o, FXSelector s, void* d);
    long onCmdSelectCell(FXObject* o, FXSelector s, void* d);
    long onCmdSelectAll(FXObject* o, FXSelector s, void* d);
    long onCmdDeselectAll(FXObject* o, FXSelector s, void* d);
    long onCmdMark(FXObject* o, FXSelector s, void* d);
    long onCmdExtend(FXObject* o, FXSelector s, void* d);


    void writeProtectCol(int col, bool val = true);


protected:
    FXTextField* myEditor;
    FXTableItem* myEditedItem;
    FXint myEditedCol, myEditedRow;
    std::set<int> myWriteProtectedCols;
    FXString myPreviousText;

protected:
    MFXEditableTable() { }

};


#endif

/****************************************************************************/

