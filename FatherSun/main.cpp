//#include <fmt/format.h>

#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <spdlog/spdlog.h>
#include "crow_all.h"
#include <chrono>
#include <thread>
#include <map>

int64_t fibonacci(int64_t n) {
	int64_t  f0 = 0;
	int64_t  f1 = 1;
	int64_t  f2 = 0;
	using namespace std::chrono_literals;
	for (int i = 0; i < n; i++) {		
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
	}
	std::this_thread::sleep_for(2s);
	return f2;
}

int main() {
	
	fmt::print("hello world\n");
	fmt::print("Mam {} lat\n", 42);

	auto logger = spdlog::stdout_logger_mt("FatherSun", true);

	logger->set_level(spdlog::level::debug);
	logger->info("Dzis Tech Day");
	logger->debug("Mówimy o C++");
	logger->error("Mielismy opoznienie");

	logger->info("{}", fibonacci(3));

	std::map<int, int64_t> fibonaci_numbers;

	crow::SimpleApp app;

	CROW_ROUTE(app, "/fibo_numbers/").methods("POST"_method)(
		[&logger, &fibonaci_numbers](const crow::request& req) {
		if (req.method == "POST"_method) {			
			logger->debug("Cialo wiadomosci {}", req.body);
			int n = stoi(req.body);
			//req.body
			//int64_t n = ? ?;
			fibonaci_numbers[n] = fibonacci(n);
			return crow::response(200);
		}
		else {
			return crow::response(200);
		}

		return crow::response(200);
	}
	);

	CROW_ROUTE(app, "/fibo_numbers/<int>")(
		[](int n) {
		
		return "";
	}
	);

	app.port(8080).multithreaded().run();

	return 0;
}

/*
CROW_ROUTE(app, "/hello")(
[]() {
return fmt::format("{}", fibonacci(5));
}
);

CROW_ROUTE(app, "/hello/<int>")(
[](int n) {
return fmt::format("{}", fibonacci(n));
}
);
*/
