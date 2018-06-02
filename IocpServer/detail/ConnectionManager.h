//! Copyright Alan Ning 2010
//! Distributed under the Boost Software License, Version 1.0.
//! (See accompanying file LICENSE_1_0.txt or copy at
//! http://www.boost.org/LICENSE_1_0.txt)

#ifndef CLIENTMANAGER_H_2010_09_25_00_05_01
#define CLIENTMANAGER_H_2010_09_25_00_05_01

namespace iocp { namespace detail { class CConnection; } };
namespace iocp { namespace detail {

class CConnectionManager
{
public:
	void AddConnection(std::shared_ptr<CConnection> client);

	bool RemoveConnection(uint64_t clientId);

	std::shared_ptr<CConnection> GetConnection(uint64_t clientId);

	void CloseAllConnections();

private:

	typedef std::map<
		uint64_t,
		std::shared_ptr<CConnection>
	> ConnMap_t;

	ConnMap_t m_connMap;

	std::mutex m_mutex;
};

} } // end namespace
#endif // CLIENTMANAGER_H_2010_09_25_00_05_01