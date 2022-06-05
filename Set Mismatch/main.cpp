/*By::Cebastian Santiago'
* Leetcode 645
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>


std::vector<int> findErrorNums(std::vector<int>& nums) {
	//sort the vector 
	std::sort(nums.begin(), nums.end());
	//create map
	std::map<int, int> hash;
	std::vector<int> temp;
	std::set<int> sets;

	//loop through vector and find the number that occurs 
	//2 times
	for (auto i : nums){
		if (hash.find(i) == hash.end()){
			hash.insert({ i,1 });
		}

		else {
			temp.push_back(i);
			break;
		}


	}


	for (auto i : nums) {
		sets.insert(i);
	}

	auto find = sets.find(1);

	if (find == sets.end()) {
		temp.push_back(1);
	}

	if (temp.size() != 2){

		for (auto i : nums) {
			find = sets.find(i+1);
			if (find == sets.end()) {
				temp.push_back(i+1);
				break;
			}
		}
	}

	return temp;

}

int main(int argv, char* argc[]) {
	std::vector<int> num = { 1,3,3};


	std::vector<int> a = findErrorNums(num);


	for (auto i : a){
		std::cout << i << std::endl;
	}


	return 0;
}

