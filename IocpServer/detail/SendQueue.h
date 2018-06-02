//! Copyright Alan Ning 2010
//! Distributed under the Boost Software License, Version 1.0.
//! (See accompanying file LICENSE_1_0.txt or copy at
//! http://www.boost.org/LICENSE_1_0.txt)

#ifndef SENDQUEUE_H_2010_09_26_12_39_06
#define SENDQUEUE_H_2010_09_26_12_39_06

namespace iocp { namespace detail { class CIocpContext; } };

namespace iocp { namespace detail {

class CSendQueue
{
public:
	~CSendQueue();

	void AddSendContext(std::shared_ptr<CIocpContext> sendContext);

	uintptr_t RemoveSendContext(CIocpContext *sendContext);

	void CloseAllSends();

	uintptr_t NumOutstandingContext();

private:
	typedef std::map<
		CIocpContext *, std::shared_ptr<CIocpContext> 
	> SendContextMap_t;

	SendContextMap_t m_sendContextMap;

	std::mutex m_mutex;
};

} } // end namespace
#endif // SENDQUEUE_H_2010_09_26_12_39_06