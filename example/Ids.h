#ifndef IDS_H_INCLUDED
#define IDS_H_INCLUDED

enum APPIDS
{
    // menu IDs
    //---------------------------------------------------------------//
    IDM_SAVEASBITMAP = wxID_HIGHEST + 1,

    // tool IDs
    //---------------------------------------------------------------//
    IDT_FIRST_TOOLMARKER,

    IDT_GRID,
    IDT_TOOL,
    IDT_RECTSHP,
    IDT_SQUARESHP,
    IDT_RNDRECTSHP,
    IDT_ELLIPSESHP,
    IDT_CIRCLESHP,
    IDT_DIAMONDSHP,
    IDT_TEXTSHP,
    IDT_EDITTEXTSHP,
    IDT_BITMAPSHP,
    IDT_LINESHP,
    IDT_CURVESHP,

    IDT_LAST_TOOLMARKER,

    // other constrols
    //---------------------------------------------------------------//
    IDT_COLORPICKER
};

#endif // IDS_H_INCLUDED
