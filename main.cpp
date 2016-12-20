#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class solution {
public:
    int maxProduct(const std::vector<std::string> & words) {
	int result;
	if (words.size() == 2) {
	    result = product(words.front(), words.back());
	}
	else {
	    int local_max = 0;
	    for (size_t i = 1; i < words.size(); ++i) {
		if (product(words.front(), words[i]) > local_max)
		    local_max = product(words.front(), words[i]);
	    }

	    result = std::max(local_max, maxProduct(std::vector<std::string>(words.begin()+1, words.end())));
	}
	return result;
    }

private:
    int product(const std::string & s1, const std::string & s2) {
	if (shareCommon(s1, s2))
	    return 0;
	else
	    return s1.size()*s2.size();
    }
    
    bool shareCommon(const std::string & w1, const std::string & w2) {
	std::string shorter, longer;
	if (w1.size() > w2.size()) {
	    shorter = w2;
	    longer = w1;
	}
	else {
	    longer = w2;
	    shorter = w1;
	}

	std::sort(longer.begin(), longer.end());
	return std::any_of(shorter.begin(), shorter.end(),
			   [&](char ch){return std::binary_search(longer.begin(), longer.end(), ch);});
    }
};

int main() {
    // std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    // std::vector<std::string> words{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    std::vector<std::string> words{"a", "aa", "aaa", "aaaa"};

    solution soln;
    int maxProd = soln.maxProduct(words);
    std::cout << "The maximum product is:\n"
	      << maxProd << std::endl;
}
