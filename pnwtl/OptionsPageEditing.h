/**
 * @file OptionsPageEditing.h
 * @brief Caret positioning and other editing options
 * @author Simon Steele
 * @note Copyright (c) 2002-2008 Simon Steele - http://untidy.net/
 *
 * Programmer's Notepad 2 : The license file (license.[txt|html]) describes 
 * the conditions under which this source may be modified / distributed.
 */

#ifndef optionspageediting_h__included
#define optionspageediting_h__included

#include "include/optionsdialog.h"

/**
 * Editing options page, options for cursor positioning etc.
 */
class COptionsPageEditing : public COptionsPageImpl<COptionsPageEditing>,
							public CWinDataExchange<COptionsPageEditing>
{
	public:
		COptionsPageEditing();

		BEGIN_MSG_MAP(COptionsPageEditing)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			REFLECT_NOTIFICATIONS()
		END_MSG_MAP()

		BEGIN_DDX_MAP(COptionsPageEditing)
			DDX_UINT(IDC_CARETSLOPX_EDIT, m_slopX)
			DDX_UINT(IDC_CARETSLOPY_EDIT, m_slopY)
			DDX_CHECK(IDC_CARETSTRICT_CHECK, m_strict)
		END_DDX_MAP()

		enum { IDD = IDD_PAGE_EDITING };

		virtual void OnOK();
		virtual void OnInitialise();
		virtual LPCTSTR GetTreePosition();
		virtual void OnCancel();

	private:
		LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

		unsigned int m_slopX;
		unsigned int m_slopY;
		BOOL m_strict;
};

#endif // #ifndef optionspageediting_h__included