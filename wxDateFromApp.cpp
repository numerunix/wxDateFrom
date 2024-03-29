/***************************************************************
 * Name:      wxDateCalcApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2022-12-14
 * Copyright: Giulio Sorrentino (https://numerone.altervista.org)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxDateFromApp.h"
#include "wxDateFromMain.h"

IMPLEMENT_APP(wxDateFromApp);

bool wxDateFromApp::OnInit()
{
    wxLocale *m_locale;
       m_locale=new wxLocale( wxLANGUAGE_DEFAULT, wxLOCALE_LOAD_DEFAULT );
       m_locale->AddCatalog("fileutils");
       wxLocale::AddCatalogLookupPathPrefix(wxT("/usr/local/share/locale"));
       wxLocale::AddCatalogLookupPathPrefix(wxT("/snap/wxdatecalc/current/usr/local/share/locale"));
       if (!m_locale->AddCatalog("wxdatefrom")) {
           wxNotificationMessage* msg = new wxNotificationMessage("Unable to find translations", "Unable to find current translation, the program will be started in english");
                       msg->Show();
                       delete msg;
       }
        m_locale->AddCatalog("wxstd");
        m_locale->AddCatalog("wxmsw");

    wxInitAllImageHandlers();
    wxDateFromFrame* frame = new wxDateFromFrame(0L, "wxDateFrom");
    frame->Show();

    return true;
}
