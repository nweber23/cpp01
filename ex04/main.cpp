#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

static std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return content;
	std::string result;
	std::size_t pos = 0;
	std::size_t found;
	while ((found = content.find(s1, pos)) != std::string::npos) {
		result.append(content, pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result.append(content, pos, content.size() - pos);
	return result;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: " << (ac > 0 ? av[0] : "replace") << " <filename> <s1> <s2>\n";
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 shouldnt be empty\n";
		return 1;
	}
	std::ifstream ifs(filename, std::ios::in | std::ios::binary);
	if (!ifs) {
		std::cerr << "Error: can not open input file '" << filename << "'\n";
		return 1;
	}
	std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();
	std::string outname = filename + ".replace";
	std::ofstream ofs(outname, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!ofs) {
		std::cerr << "Error: cannot create output file '" << outname << "'\n";
		return 1;
	}
	std::string replaced = replaceAll(content, s1, s2);
	ofs << replaced;
	ofs.close();

	return 0;
}