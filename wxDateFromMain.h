/***************************************************************
 * Name:      wxDateCalcMain.h
 * Purpose:   Defines Application Frame
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2022-12-14
 * Copyright: Giulio Sorrentino (https://numerone.altervista.org)
 * License:
 **************************************************************/

#ifndef WXDATEFROMMAIN_H
#define WXDATEFROMMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/calctrl.h>
#include <wx/aboutdlg.h>
#include <wx/config.h>
#include <wx/datetime.h>
#include <wx/utils.h>
#include <wx/notifmsg.h>
#include <wx/filename.h>

#include "wxDateFromApp.h"
#include "background.xpm"

class wxDateFromFrame: public wxFrame
{
    public:
        wxDateFromFrame(wxFrame *frame, const wxString& title);
        ~wxDateFromFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            ID_BUTTON_OK
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOk(wxCommandEvent &evt);
        void OnPaint(wxPaintEvent &evt);
        void salvaData();

	wxTextCtrl *nome;
        wxCalendarCtrl  *calendar;
        wxButton *calcola;
        wxImage *img;
        wxConfig *config;
        wxDateTime data;
        wxStaticText *result;
        DECLARE_EVENT_TABLE()
};


#endif // WXDATEFROMMAIN_H
