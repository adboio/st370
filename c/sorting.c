#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shuffle( int arr[], int n )
{
  srand( time( NULL ) );

  for ( int i = n - 1; i > 0; i-- ) {
    int j = rand() % ( i + 1 );
    swap( &arr[ i ], &arr[ j ] );
  }
}

void bubbleSort( int arr[], int n )
{
  int i, j;
  for ( i = 0; i < n - 1; i++ ) {
    for ( j = 0; j < n - i - 1; j++ ) {
      if ( arr[ j ] > arr[ j + 1 ] ) {
        swap( &arr[ j ], &arr[ j + 1 ] );
      }
    }
  }
}

void selectionSort( int arr[], int n )
{
  int i, j, minIdx;

  for ( i = 0; i < n - 1; i++ ) {
    minIdx = i;
    for ( j = i + 1; j < n; j++ ) {
      if ( arr[ j ] < arr[ minIdx ] ) {
        minIdx = j;
      }
    }
    swap( &arr[ minIdx ], &arr[ i ] );
  }
}

void merge( int arr[], int l, int m, int r )
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;

  int L[ n1 ], R[ n2 ];

  for (i = 0; i < n1; i++) {
      L[ i ] = arr[ l + i ];
  }

  for ( j = 0; j < n2; j++ ) {
      R[ j ] = arr[ m + 1+ j ];
  }

  i = 0;
  j = 0;
  k = l;
  while ( i < n1 && j < n2 ) {
    if ( L[ i ] <= R[ j ] ) {
      arr[ k ] = L[ i ] ;
      i++;
    } else {
      arr[ k ] = R[ j ];
      j++;
    }
    k++;
  }

  while ( i < n1 ) {
    arr[ k ] = L[ i ];
    i++;
    k++;
  }

  while ( j < n2 ) {
    arr[ k ] = R[ j ];
    j++;
    k++;
  }
}

void mergeSort( int arr[], int l, int r )
{
  if ( l < r ) {
    int m = l + ( r - l ) / 2;

    mergeSort( arr, l, m );
    mergeSort( arr, m+1, r );

    merge( arr, l, m, r );
  }
}

int partition( int arr[], int low, int high )
{
  int pivot = arr[ high ];
  int i = ( low - 1 );

  for ( int j = low; j <= high- 1; j++ ) {
    if ( arr[ j ] <= pivot ) {
      i++;
      swap( &arr[ i ], &arr[ j ] );
    }
  }
  swap( &arr[ i + 1 ], &arr[ high ] );
  return ( i + 1 );
}

void quickSort( int arr[], int low, int high )
{
  if ( low < high ) {
    int pi = partition( arr, low, high );

    quickSort( arr, low, pi - 1 );
    quickSort( arr, pi + 1, high );
  }
}

void printArray( int arr[], int n )
{
  for ( int i = 0; i < n; i++ ) {
    printf( "%d ", arr[ i ] );
  }
  printf( "\n" );
}

void printResults( double b, double s, double m, double q )
{
  printf( "~~~~~~~~~~RESULTS~~~~~~~~~~\n" );
  printf( "<Algorithm>       <Runtime>\n" );
  printf( "MergeSort         %lf\n", m );
  printf( "QuickSort         %lf\n", q );
  printf( "SelectionSort     %lf\n", s );
  printf( "BubbleSort        %lf\n", b );
}

int main( int argc, char *argv[] )
{
  if ( argc != 2 ) {
    printf( "usage: ./sorting <size>\n" );
    exit( 1 );
  }

  // convert cmd arg to integer
  int size = atoi( argv[ 1 ] );

  // generate random array
  int randomArray[ size ];
  for ( int i = 0; i < size; i++ ) {
    randomArray[ i ] = i;
  }
  shuffle( randomArray, size );

  // execute various sorting methods
  clock_t t;

  // bubble sort
  int b[ size ];
  memcpy( b, randomArray, sizeof( b ) );

  t = clock();
  bubbleSort( b, size );
  t = clock() - t;

  double bTime = ( ( double ) t ) / CLOCKS_PER_SEC;

  // selection sort
  int s[ size ];
  memcpy( s, randomArray, sizeof( s ) );

  t = clock();
  selectionSort( s, size );
  t = clock() - t;

  double sTime = ( ( double ) t ) / CLOCKS_PER_SEC;

  // merge sort
  int m[ size ];
  memcpy( m, randomArray, sizeof( m ) );

  t = clock();
  mergeSort( m, 0, size - 1 );
  t = clock() - t;

  double mTime = ( ( double ) t ) / CLOCKS_PER_SEC;


  // quick sort
  int q[ size ];
  memcpy( q, randomArray, sizeof( q ) );

  t = clock();
  quickSort( q, 0, size - 1 );

  t = clock() - t;
  double qTime = ( ( double ) t ) / CLOCKS_PER_SEC;

  printResults( bTime, sTime, mTime, qTime );
}
