/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */

#if defined(GD_IDE_ONLY)
#include "EditForEachEvent.h"

//(*InternalHeaders(EditForEachEvent)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include "GDL/ForEachEvent.h"
#include "GDCore/IDE/Dialogs/ChooseObjectDialog.h"
#include "GDCore/Tools/HelpFileAccess.h"
#include "GDL/CommonTools.h"
#include "GDL/Game.h"
#include "GDL/Scene.h"

//(*IdInit(EditForEachEvent)
const long EditForEachEvent::ID_STATICTEXT1 = wxNewId();
const long EditForEachEvent::ID_TEXTCTRL1 = wxNewId();
const long EditForEachEvent::ID_BITMAPBUTTON1 = wxNewId();
const long EditForEachEvent::ID_STATICLINE1 = wxNewId();
const long EditForEachEvent::ID_STATICBITMAP2 = wxNewId();
const long EditForEachEvent::ID_HYPERLINKCTRL1 = wxNewId();
const long EditForEachEvent::ID_BUTTON1 = wxNewId();
const long EditForEachEvent::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EditForEachEvent,wxDialog)
	//(*EventTable(EditForEachEvent)
	//*)
END_EVENT_TABLE()

EditForEachEvent::EditForEachEvent(wxWindow* parent, ForEachEvent & event_, Game & game_, Scene & scene_) :
eventEdited(event_),
game(game_),
scene(scene_)
{
	//(*Initialize(EditForEachEvent)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Edition of \"For each object\" event"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Repeat event for each object:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	objectEdit = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer4->Add(objectEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	objectBt = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res/objeticon.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	objectBt->SetDefault();
	FlexGridSizer4->Add(objectBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer5->AddGrowableRow(0);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(_T("res/helpicon.png"))), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_STATICBITMAP2"));
	FlexGridSizer5->Add(StaticBitmap1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	helpBt = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("Help"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
	helpBt->SetToolTip(_("Display help about this window"));
	FlexGridSizer5->Add(helpBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(okBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	cancelBt = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(cancelBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditForEachEvent::OnobjectBtClick);
	Connect(ID_HYPERLINKCTRL1,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&EditForEachEvent::OnhelpBtClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditForEachEvent::OnokBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditForEachEvent::OncancelBtClick);
	//*)

    objectEdit->ChangeValue(eventEdited.GetObjectToPick());
}

EditForEachEvent::~EditForEachEvent()
{
	//(*Destroy(EditForEachEvent)
	//*)
}


void EditForEachEvent::OnokBtClick(wxCommandEvent& event)
{
    eventEdited.SetObjectToPick(ToString(objectEdit->GetValue()));
    EndModal(1);
}

void EditForEachEvent::OncancelBtClick(wxCommandEvent& event)
{
    EndModal(0);
}

void EditForEachEvent::OnobjectBtClick(wxCommandEvent& event)
{
    gd::ChooseObjectDialog dialog(this, game, scene, true);
    if ( dialog.ShowModal() == 1 )
        objectEdit->ChangeValue(dialog.GetChosenObject());

    return;
}

void EditForEachEvent::OnhelpBtClick(wxCommandEvent& event)
{
    gd::HelpFileAccess::GetInstance()->OpenURL(_("http://wiki.compilgames.net/doku.php/en/game_develop/documentation/manual/foreach_events"));
}

#endif
