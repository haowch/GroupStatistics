#include <iostream>
#include <fstream>
#include <vector>

void Statistics(std::vector<int> &count)
{
	std::vector<int>::iterator i = count.begin();
	std::ofstream fout("C:\\test\\Statistics.txt");
	int icount;
	int itemp;
	while (i != count.end())
	{
		itemp = *i;
		icount = 0;
		while (i != count.end() && (*i) == itemp)
		{
			++icount;
			++i;
		}
		fout << "Number of Signatures that have " << itemp << " Sids:";
		fout << icount << std::endl;
	}
	fout.close();
}

void ReadResultFile(std::vector<int> &count)
{
	std::ifstream fin("C:\\test\\ResultsWithoutRules.txt", std::ios::in);
	
	int itemp;
	while (fin >> itemp)
	{
		count.push_back(itemp);
	}
	fin.close();
}

void main()
{
	std::vector<int> count;

	ReadResultFile(count);

	Statistics(count);

	system("pause");
}