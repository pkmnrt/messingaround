#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_NUM_AFFLICTIONS 500

int main( int argc, char** argv )
{
    FILE* fp = NULL;
    char afflictions[ MAX_NUM_AFFLICTIONS ][ MAX_STRING_LENGTH ] = { 0 };
    int index = 0;
    int total = 0;
    int input = 0;

    fp = fopen( "afflictions.txt", "r" );
    if( fp )
    {
        while( fgets( afflictions[ index ], MAX_STRING_LENGTH, fp ) )
        {
            if( strlen( afflictions[ index ] ) > 2 )
            {
                index++;
            }
            // else, zero-length string, so leave index the same to overwrite next time around.

            if( index > MAX_NUM_AFFLICTIONS + 1 )
            {
                printf( "Too many afflictions in file.\n" );
                return 0;
            }
        }

        total = index - 1;

        fclose( fp );

        printf( "Found %d afflictions. Press <Enter> for a random affliction.\n", total );

        srand( time( NULL ) );

        while( 1 )
        {
            input = getchar();

            index = rand() % ( total + 1 );

            printf( "Affliction #%d: %s", ( index + 1 ), afflictions[ index ] );
        }
    }
    else
    {
        printf( "Failed to find afflictions.txt file.\n" );
    }

    return 0;
}

