#ifndef test_hpp
#define test_hpp

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

template<typename T>
class Test {
	virtual ~Test() = default;
	virtual boost::asio::awaitable<std::shared_ptr<T>> asyncAccept() = 0;
};

#endif /* test_hpp */
