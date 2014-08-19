#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jsmn.h"

int main()
{
	int length;
	const char *js;

	int resultCode;
	jsmn_parser p;
	jsmntok_t tokens[12];

	jsmn_init(&p);

	js = "{ 'data1':[1,2,3], 'data2':[4,5,6] }"; 

	resultCode = jsmn_parse( &p, js, strlen(js), tokens, 12 );

	// switch case on resultCode; exit on error
	if( resultCode < 0 )
	{
		puts( "Parsing error.");
		return 1;
	} // if resultCode
	else
		printf( "Parsed the string; found %d objects\n", resultCode );
	
	// print the parsed message
	int i, len;
	jsmntok_t key;
	for( i = 0; i < resultCode; i++ )
	{
		key = tokens[i];
		len = key.end - key.start;
		char keyString[ len+1 ];
		memcpy( keyString, &js[ key.start ], len );
		keyString[ len ] = '\0';
		printf( "Key[%d]: %s\n", i, keyString );
	} // for i
	
	return 0;

} // main
