#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>

using boost::asio::ip::tcp;



class Session: public std::enable_shared_from_this<Session> {
public:
	Session(tcp::socket socket) : socket_(std::move(socket)), buff_(BUFF_SIZE) {}
	void start(){
		read();
	}
	void read() {
		auto self(shared_from_this());
		boost::asio::async_read_until(socket_, buff_, '\n', [this, self](boost::system::error_code ec, size_t bytesRead) {
			if (!ec) {
				std::istream is(&buff_);
				std::string line;
				std::getline(is, line);
				
				std::cout << "read success : " << line << std::endl;
				read();
			} else {
				std::cerr << "error in reading " << ec.message() << std::endl;
				socket_.close();
			}
		});
	}
	
private:
	tcp::socket socket_;
//	std::vector<char> buff_;
	boost::asio::streambuf buff_;
	static constexpr int BUFF_SIZE = 32;
};

class Server {
public:
	Server(boost::asio::io_context& io_context, tcp::endpoint& endpoint)
	: acceptor_(io_context, endpoint) {
		accept();
	}
	void accept() {
		acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
			if (!ec) {
				std::cout << "client accepted! " << std::endl;
				std::make_shared<Session>(std::move(socket))->start();
			} else {
				std::cerr << "error in acception" << ec.message() << std::endl;
			}
			accept();
		});
	}
private:
	tcp::acceptor acceptor_;
};

int main(int argc, const char * argv[]) {
	std::string port = "4000";
	boost::asio::io_context io_context;
	tcp::endpoint endpoint(tcp::v4(), stoi(port));
	Server server(io_context, endpoint);
	io_context.run();
	
	return 0;
}
