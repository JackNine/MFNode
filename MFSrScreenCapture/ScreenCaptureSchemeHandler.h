//----------------------------------------------------------------------------------------------
// ScreenCaptureSchemeHandler.h
// Copyright (C) 2013 Dumonteil David
//
// MFNode is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MFNode is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------------------------------
#ifndef SCREENCAPTURESCHEMEHANDLER_H
#define SCREENCAPTURESCHEMEHANDLER_H

class CScreenCaptureSchemeHandler : BaseObject, public IMFSchemeHandler{

  public:
				
				static HRESULT CreateInstance(IUnknown*, REFIID, void**);

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID, void**);
				STDMETHODIMP_(ULONG) AddRef();
				STDMETHODIMP_(ULONG) Release();

				// IMFSchemeHandler
    STDMETHODIMP BeginCreateObject(LPCWSTR, DWORD, IPropertyStore*, IUnknown**, IMFAsyncCallback*, IUnknown*);
				STDMETHODIMP CancelObjectCreation(IUnknown*){ return E_NOTIMPL; }
				STDMETHODIMP EndCreateObject(IMFAsyncResult*, MF_OBJECT_TYPE*, IUnknown**);

  private:

				CScreenCaptureSchemeHandler() : m_nRefCount(1){ TRACE_SCHEME((L"Scheme::CTOR")); }
				virtual ~CScreenCaptureSchemeHandler(){ TRACE_SCHEME((L"Scheme::DTOR")); }

				volatile long m_nRefCount;
};

#endif