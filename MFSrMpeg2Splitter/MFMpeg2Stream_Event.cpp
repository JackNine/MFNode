//----------------------------------------------------------------------------------------------
// MFMpeg2Stream_Event.cpp
// Copyright (C) 2014 Dumonteil David
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
#include "StdAfx.h"

HRESULT CMFMpeg2Stream::BeginGetEvent(IMFAsyncCallback* pCallback, IUnknown* punkState){
		
		TRACE_EVENTSTREAM((L"Stream::BeginGetEvent"));
		
		HRESULT hr;

		SourceLock lock(m_pSource);

		IF_FAILED_RETURN(hr = CheckShutdown());
		IF_FAILED_RETURN(hr = m_pEventQueue->BeginGetEvent(pCallback, punkState));

		return hr;
}

HRESULT CMFMpeg2Stream::EndGetEvent(IMFAsyncResult* pResult, IMFMediaEvent** ppEvent){
		
		TRACE_EVENTSTREAM((L"Stream::EndGetEvent"));
		
		HRESULT hr;

		SourceLock lock(m_pSource);

		IF_FAILED_RETURN(hr = CheckShutdown());
		IF_FAILED_RETURN(hr = m_pEventQueue->EndGetEvent(pResult, ppEvent));

		return hr;
}

HRESULT CMFMpeg2Stream::GetEvent(DWORD dwFlags, IMFMediaEvent** ppEvent){
		
		TRACE_EVENTSTREAM((L"Stream::GetEvent"));

		HRESULT hr;

		IMFMediaEventQueue* pQueue = NULL;

		{
				SourceLock lock(m_pSource);
				
				IF_FAILED_RETURN(hr = CheckShutdown());

				pQueue = m_pEventQueue;
				pQueue->AddRef();
		}

		LOG_HRESULT(hr = pQueue->GetEvent(dwFlags, ppEvent));

		SAFE_RELEASE(pQueue);
		
		return hr;
}

HRESULT CMFMpeg2Stream::QueueEvent(MediaEventType met, REFGUID guidExtendedType, HRESULT hrStatus, const PROPVARIANT* pvValue){
		
		TRACE_EVENTSTREAM((L"Stream::QueueEvent"));
		
		HRESULT hr;

		SourceLock lock(m_pSource);

		IF_FAILED_RETURN(hr = CheckShutdown());
		IF_FAILED_RETURN(hr = m_pEventQueue->QueueEventParamVar(met, guidExtendedType, hrStatus, pvValue));

		return hr;
}