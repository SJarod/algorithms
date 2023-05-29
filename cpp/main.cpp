#include "helloworld.hpp"
#include "longestcommonprefix.hpp"

int main()
{
	helloWorld();

	std::cout << longestCommonPrefix({ "Flower", "Fly", "Flee", "Fl" }) << std::endl; // Fl
	std::cout << longestCommonPrefix({ "FL", "Flower", "Fly", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "F", "Flower", "Fly", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "Fyds", "Flower", "Fly", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "Fs", "Flower", "Fly", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "Flower", "Fly", "Flee", "Fl", "fkdls" }) << std::endl; // None
	std::cout << longestCommonPrefix({ "Flower", "Fly", "Flee", "Fl", "f" }) << std::endl; // None
	std::cout << longestCommonPrefix({ "Flower", "Fly", "FL", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "Flower", "Fly", "Fw", "Flee", "Fl" }) << std::endl; // F
	std::cout << longestCommonPrefix({ "Flower", "Fly", "Fdsw", "Flee", "Fl" }) << std::endl; // F


	return 0;
}