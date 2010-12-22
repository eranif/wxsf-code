/***************************************************************
 * Name:      AutoLayout.h
 * Purpose:   Declares class for autolayouting algoriths' provider
 * Author:    Michal Bližňák (michal.bliznak@tiscali.cz)
 * Created:   2010-12-22
 * Copyright: Michal Bližňák
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#ifndef _WXSFAUTOLAYOUT_H_
#define _WXSFAUTOLAYOUT_H_

#include <wx/wxsf/DiagramManager.h>

#include <wx/hashmap.h>

class WXDLLIMPEXP_SF wxSFLayoutAlgorithm : public wxObject
{
public:
	virtual ~wxSFLayoutAlgorithm() {;}
	
	virtual void DoLayout(ShapeList &shapes) = 0;
};

WX_DECLARE_HASH_MAP( wxString, wxSFLayoutAlgorithm*, wxStringHash, wxStringEqual, LayoutAlgoritmMap );
	
class WXDLLIMPEXP_SF wxSFAutoLayout
{
public:
	wxSFAutoLayout();
	~wxSFAutoLayout();

	void Layout(ShapeList &shapes, const wxString& algname);
	void Layout(wxSFDiagramManager &manager, const wxString& algname);
	void Layout(wxSFShapeCanvas *canvas, const wxString& algname);
	
	static bool RegisterLayoutAlgorithm(const wxString& algname, wxSFLayoutAlgorithm *alg);
	static void CleanUp();
	
	wxArrayString GetRegisteredAlgorithms();
	
protected:
	void InitializeAllAlgorithms();
	
	static LayoutAlgoritmMap m_mapAlgorithms;
	
};

// pre-defined algorithms //////////////////////////////////////////////////////

class wxSFLayoutCircle : public wxSFLayoutAlgorithm
{
public:
	virtual ~wxSFLayoutCircle() {;}
	
	virtual void DoLayout(ShapeList &shapes);
};

class wxSFLayoutTree : public wxSFLayoutAlgorithm
{
public:
	virtual ~wxSFLayoutTree() {;}
	
	virtual void DoLayout(ShapeList &shapes);
};

class wxSFLayoutMesh : public wxSFLayoutAlgorithm
{
public:
	virtual ~wxSFLayoutMesh() {;}
	
	virtual void DoLayout(ShapeList &shapes);
};

#endif //_WXSFAUTOLAYOUT_H_