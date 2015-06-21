
#include <iostream>
using namespace std;
using std::cout;

#include <map>

char FirstUniqueChar_Using_Array( std::string strInput )
{
	int charList[255] = {0};

	for ( auto it = strInput.begin(); it != strInput.end(); it++ )
	{
		charList[*it]++;
	}

	for ( auto it = strInput.begin(); it != strInput.end(); it++ )
	{
		if ( charList[*it] == 1 )
			return ( *it );
	}

	return NULL;
}

char FirstUniqueChar_Using_Hash_Map( std::string strInput )
{
	std::map<char, int> mCharMap;

	for ( auto it = strInput.begin( ); it != strInput.end( ); it++ )
	{
		if ( mCharMap.find( *it ) != mCharMap.end() )
		{
			mCharMap[*it]++;
		}
		else
		{
			mCharMap[*it] = 1;
		}
	}

	for ( auto it = strInput.begin( ); it != strInput.end( ); it++ )
	{
		if ( mCharMap[*it] == 1 )
			return ( *it );
	}

	return NULL;
}

std::string RemoveSpecifiedCharacters( std::string strInput, std::string strRemove )
{
	int size = strInput.length();

	std::map<char, int> mRemoveMap;
	for ( auto it = strRemove.begin(); it != strRemove.end(); it++ )
	{
		mRemoveMap[*it];
	}

	auto iUpdate = strInput.begin();
	for ( auto it = strInput.begin(); it != strInput.end(); it++ )
	{
		if ( mRemoveMap.find( *it ) == mRemoveMap.end() )
		{
			*iUpdate = *it;
			iUpdate++;
		}
	}

	return string( strInput.begin(), iUpdate );
}

std::string ReverseWordsInSentence( std::string strInput )
{
	//TODO: Fix Bug, last word is not written over the input string...
	//TODO: Switch to using another buffer ?

	std::string strOutput = strInput;

	auto itRevString = strOutput.begin();
	auto itScan = strInput.rbegin();

	while ( itScan != strInput.rend() )
	{
		if ( *itScan == ' ' )
		{
			auto itCopy = itScan - 1;

			while ( (*itCopy) != ' ' && itCopy != strInput.rbegin() )
			{
				*itRevString = *itCopy;
				itCopy--;
				itRevString++;
			}

			*itRevString = ' ';
			itRevString++;
		}

		itScan++;
	}

	return strOutput;
}

std::string ReverseWords( std::string strInput )
{
    // "Hello World"

    std::string strOutput;

    auto wordStart = strInput.begin();
    auto wordEnd = strInput.begin() + 1;

    while ( wordEnd != strInput.end() )
    {
        if ( *wordEnd == ' ' )
        {
            strOutput = std::string( wordStart, wordEnd ) + " " + strOutput;
            wordStart = wordEnd + 1;
        }

        wordEnd++;
    }
    strOutput = std::string( wordStart, wordEnd ) + " " + strOutput;

    return strOutput;
}


int main( void )
{
	cout << FirstUniqueChar_Using_Array( "total" ) << endl;
	cout << FirstUniqueChar_Using_Array( "teeter " ) << endl;
	cout << FirstUniqueChar_Using_Hash_Map( "total" ) << endl;
	cout << FirstUniqueChar_Using_Hash_Map( "teeter " ) << endl;

	cout << RemoveSpecifiedCharacters( "hello world. My name is Mohamed.", "aeiou" ).c_str() << endl; 

	cout << ReverseWordsInSentence( "Hello, my name is Mohamed." ).c_str() << endl;

    cout << ReverseWords( "Hello World This is Mohamed" ).c_str() << endl;

	return 0;
}