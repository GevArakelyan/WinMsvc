#include <format>




namespace {



	void ex() {
		auto res1 = std::format("{:<10}", "hi");

		auto res2 = std::format("{:_^10}", "hey");
		auto res3 = std::format("{:_<10}", "hi");
		auto res4 = std::format("{:_>10}", "hi");

		auto res5 = std::format("{:10}", 3.4);
		auto res6 = std::format("{:2}", 3820.45);
		auto res7 = std::format("{:.2f}", 100.345736);
		auto res8 = std::format("{:.2f}", 1000000.);
		

		auto res = 0;
	}



}




int main() {
	ex();


	return 0;
}