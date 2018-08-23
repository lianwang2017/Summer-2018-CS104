#include "cmdhandler.h"
#include "util.h"
using namespace std;

QuitHandler::QuitHandler()
{

}

QuitHandler::QuitHandler(Handler* next)
  : Handler(next)
{

}

bool QuitHandler::canHandle(const std::string& cmd) const
{
	return cmd == "QUIT";

}

Handler::HANDLER_STATUS_T QuitHandler::process(TwitEng* eng, std::istream& instr) const
{
	eng->dumpFeeds();
	return HANDLER_QUIT;
}

// ANDHandler
AndHandler::AndHandler()
{

}

AndHandler::AndHandler(Handler* next)
  : Handler(next)
{

}

bool AndHandler::canHandle(const std::string& cmd) const
{
	return cmd == "AND";

}

// this is where we do stuff
Handler::HANDLER_STATUS_T AndHandler::process(TwitEng* eng, std::istream& instr) const
{
	vector<string> searchterms;
	string word;
	// adding search terms to a vector
	while (instr >> word)
		searchterms.push_back(word);
	// calling search function from twiteng to execute 
	vector<Tweet* > results = eng->search(searchterms, 0);
	displayHits(results);
	return HANDLER_OK;
}

// ORHandler
OrHandler::OrHandler()
{

}

OrHandler::OrHandler(Handler* next)
  : Handler(next)
{

}

bool OrHandler::canHandle(const std::string& cmd) const
{
	return cmd == "OR";

}

Handler::HANDLER_STATUS_T OrHandler::process(TwitEng* eng, std::istream& instr) const
{
	vector<string> searchterms;
	string word;
	// adding search terms to a vector
	while (instr >> word)
		searchterms.push_back(word);
	// calling search function from twiteng to execute 
	vector<Tweet* > results = eng->search(searchterms, 1);
	displayHits(results);
	return HANDLER_OK;
}

// TweetHandler
TweetHandler::TweetHandler()
{

}

TweetHandler::TweetHandler(Handler* next)
  : Handler(next)
{

}

bool TweetHandler::canHandle(const std::string& cmd) const
{
	return cmd == "TWEET";

}

Handler::HANDLER_STATUS_T TweetHandler::process(TwitEng* eng, std::istream& instr) const
{
	string input_user;
	instr >> input_user;
	
	string tweet_text;
	getline(instr, tweet_text);
	trim(tweet_text);

	DateTime curr_dt = DateTime();
	eng->addTweet(input_user, curr_dt, tweet_text);

	return HANDLER_OK;
}
