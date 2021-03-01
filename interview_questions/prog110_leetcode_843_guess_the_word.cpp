#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

// hasMatch(word1, word2, -1) return counts all matches
// hasMatch(word1, word2, 0) return 1 if has no thing in common
// hasmatch(word1, word2, 1) return 1 if has at least 1 thing in common

int hasMatch(std::string word1,
	std::string word2,
	int count = -1)
{
	int size1 = word1.length();
	int size2 = word2.length();

	if (size1 != size2) return -1;

	int currCount = 0;
	for (int i = 0; i < size1; i++)
	{
		if (word1[i] == word2[i])
		{
			currCount++;
		}

		if (count == -1) continue;

		if (count != 0 && count == currCount) return currCount;
	}

	if (count == -1) return currCount;

	if (count == 0) return count == currCount;

	if (currCount < count)  return 0;

	return currCount;
}

class Master
{
public:
	Master(std::vector<std::string> wordList,
		std::string secretWord)
		: _wordList(wordList), _secretWord(secretWord)
	{}
	int guess(std::string word);
private:
	std::vector<std::string> _wordList;
	std::string _secretWord;
};

int Master::guess(std::string word)
{
	if (std::find(_wordList.begin(), _wordList.end(), word)
		== _wordList.end())
	{
		return -1;
	}

	return hasMatch(word, _secretWord);
}

void removeSimilarCount(std::vector<std::string>& wordList,
	std::string currWord, int count)
{
	if (count < 0)
		return;

	std::vector<std::string>::iterator tempWordIt = wordList.begin();

	// if count is zero means that the secret word
	// does not contain any of the words in currWord,
	// therefore we delete all the words that has at
	// least a character in common
	if (count == 0)
	{
		while (tempWordIt != wordList.end())
		{
			if (hasMatch(*tempWordIt, currWord, 1))
			{
				tempWordIt = wordList.erase(tempWordIt);
			}
			else {
				tempWordIt++;
			}
		}
		return;
	}

	tempWordIt = wordList.begin();

	while (tempWordIt != wordList.end())
	{
		if (!hasMatch(*tempWordIt, currWord, count))
		{
			tempWordIt = wordList.erase(tempWordIt);
		}
		else
		{
			tempWordIt++;
		}
	}

	std::vector<std::string>::iterator it =
		std::find(wordList.begin(), wordList.end(), currWord);

	wordList.erase(it);
	return;
}

void findSecretWord(std::vector<std::string>& wordlist, Master& master) {
	std::string currWord;
	int count;
    srand(static_cast<unsigned int> (time(0)));
	for (int i = 1; i <= 10; i++)
	{
        int idx = rand() % wordlist.size();
		currWord = wordlist[idx];
        std::cout << "[" << i << "] word: " << currWord << std::endl;
		count = master.guess(currWord);
        std::cout << "master.guess result: " << count << std::endl;

		if (count == 6)
		{
            std::cout << "=========" << std::endl;
			std::cout << currWord << std::endl;
            std::cout << "=========" << std::endl;
			return;
		}

        auto currLen = wordlist.size();
		removeSimilarCount(wordlist, currWord, count);

        std::cout   << static_cast<int>(currLen - wordlist.size()) << " words removed"
                    << "(" << wordlist.size() << " words left)" << std::endl;
	}
}

int main()
{
	std::vector<std::string> wordlist =
	{"yyyyyy","iiiiii","ccbazz","xxxxzz","eiowzz","abcczz","acckzz"};

	std::string secret = "acckzz";

	Master master(wordlist, secret);

	findSecretWord(wordlist, master);

    std::vector<std::string> wordlist2{"wichbx","oahwep","tpulot","eqznzs","vvmplb","eywinm","dqefpt","kmjmxr","ihkovg","trbzyb","xqulhc","bcsbfw","rwzslk","abpjhw","mpubps","viyzbc","kodlta","ckfzjh","phuepp","rokoro","nxcwmo","awvqlr","uooeon","hhfuzz","sajxgr","oxgaix","fnugyu","lkxwru","mhtrvb","xxonmg","tqxlbr","euxtzg","tjwvad","uslult","rtjosi","hsygda","vyuica","mbnagm","uinqur","pikenp","szgupv","qpxmsw","vunxdn","jahhfn","kmbeok","biywow","yvgwho","hwzodo","loffxk","xavzqd","vwzpfe","uairjw","itufkt","kaklud","jjinfa","kqbttl","zocgux","ucwjig","meesxb","uysfyc","kdfvtw","vizxrv","rpbdjh","wynohw","lhqxvx","kaadty","dxxwut","vjtskm","yrdswc","byzjxm","jeomdc","saevda","himevi","ydltnu","wrrpoc","khuopg","ooxarg","vcvfry","thaawc","bssybb","ccoyyo","ajcwbj","arwfnl","nafmtm","xoaumd","vbejda","kaefne","swcrkh","reeyhj","vmcwaf","chxitv","qkwjna","vklpkp","xfnayl","ktgmfn","xrmzzm","fgtuki","zcffuv","srxuus","pydgmq"};
    std::string secret2= "ccoyyo";
    Master master2(wordlist2, secret2);
    findSecretWord(wordlist2, master2);


    std::vector<std::string> wordlist3{"gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"};
    std::string secret3 = "hbaczn";
    Master master3(wordlist3, secret3);
    
    findSecretWord(wordlist3, master3);

    std::string secret4 = "vftnkr";
    std::vector<std::string> wordlist4{"mjpsce","giwiyk","slbnia","pullbr","ezvczd","dwkrmt","qgzebh","wvhhlm","kqbmny","zpvrkz","pdwxvy","gilywa","gmrrdc","vvqvla","rmjirt","qmvykq","mhbmuq","unplzn","qkcied","eignxg","fbfgng","xpizga","twubzr","nnfaxr","skknhe","twautl","nglrst","mibyks","qrbmpx","ukgjkq","mhxxfb","deggal","bwpvsp","uirtak","tqkzfk","hfzawa","jahjgn","mteyut","jzbqbv","ttddtf","auuwgn","untihn","gbhnog","zowaol","feitjl","omtiur","kwdsgx","tggcqq","qachdn","dixtat","hcsvbw","chduyy","gpdtft","bjxzky","uvvvko","jzcpiv","gtyjau","unsmok","vfcmhc","hvxnut","orlwku","ejllrv","jbrskt","xnxxdi","rfreiv","njbvwj","pkydxy","jksiwj","iaembk","pyqdip","exkykx","uxgecc","khzqgy","dehkbu","ahplng","jomiik","nmcsfe","bclcbp","xfiefi","soiwde","tcjkjp","wervlz","dcthgv","hwwghe","hdlkll","dpzoxb","mpiviy","cprcwo","molttv","dwjtdp","qiilsr","dbnaxs","dbozaw","webcyp","vftnkr","iurlzf","giqcfc","pcghoi","zupyzn","xckegy"};
    Master master4(wordlist4, secret4);

    findSecretWord(wordlist4, master4);

    return 0;
}