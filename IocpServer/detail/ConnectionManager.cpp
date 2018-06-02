//! Copyright Alan Ning 2010
//! Distributed under the Boost Software License, Version 1.0.
//! (See accompanying file LICENSE_1_0.txt or copy at
//! http://www.boost.org/LICENSE_1_0.txt)

#include "StdAfx.h"
#include "ConnectionManager.h"
#include "Connection.h"

namespace iocp { namespace detail {

void CConnectionManager::AddConnection( std::shared_ptr<CConnection> client )
{
	//mutex::scoped_lock lock(m_mutex);
	std::lock_guard<std::mutex> lock(m_mutex);

	bool inserted = m_connMap.insert(std::make_pair(
		client->m_id, client
		)).second;

	assert(true == inserted);
}

bool CConnectionManager::RemoveConnection( uint64_t clientId )
{
	//mutex::scoped_lock lock(m_mutex);
	std::lock_guard<std::mutex> lock(m_mutex);
	return (m_connMap.erase(clientId) > 0);
}

std::shared_ptr<CConnection> CConnectionManager::GetConnection( uint64_t clientId )
{
	//mutex::scoped_lock lock(m_mutex);

	std::lock_guard<std::mutex> lock(m_mutex);

	auto itr = m_connMap.find(clientId);

	if(m_connMap.end() != itr)
	{
		return itr->second;
	}

	return std::shared_ptr<CConnection>();
}

void CConnectionManager::CloseAllConnections()
{
	//mutex::scoped_lock lock(m_mutex);

	std::lock_guard<std::mutex> lock(m_mutex);

	auto itr = m_connMap.begin();
	while(m_connMap.end() != itr)
	{
		CancelIo((HANDLE)itr->second->m_socket);
		++itr;
	}
}
} } // end namespace
