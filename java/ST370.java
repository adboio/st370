import java.util.ArrayList;
import java.util.Collections;
import java.lang.System;

import sorter.MergeSort;
import sorter.QuickSort;

public class ST370 {

	public static final int SMALL = 10;
	public static final int MEDIUM = 1000;
	public static final int LARGE = 100000;
	public static final int CONVERSION = 1000000;

	public static void main(String[] args) {

		if (args.length == 0) {
			System.out.println("usage: java ST370 <size>");
			System.exit(1);
		}
		int size = Integer.parseInt(args[0]);

		// generate random array
		int[] randomArray = randomArrayGenerator(size);

		long startTime, endTime;

		// execute mergeSort and time
		int[] ra1 = new int[size];
		System.arraycopy(randomArray, 0, ra1, 0, randomArray.length);
		startTime = System.nanoTime();
		MergeSort ms = new MergeSort();
		ms.sort(ra1, 0, ra1.length - 1);
		endTime = System.nanoTime();
		long mergeSortTime = (endTime - startTime);

		// execute selectionSort and time
		int[] ra2 = new int[size];
		System.arraycopy(randomArray, 0, ra2, 0, randomArray.length);
		startTime = System.nanoTime();
		ra2 = selectionSort(ra2);
		endTime = System.nanoTime();
		long selectionSortTime = (endTime - startTime);

		// execute quickSort and time
		int[] ra3 = new int[size];
		System.arraycopy(randomArray, 0, ra3, 0, randomArray.length);
		startTime = System.nanoTime();
		QuickSort qs = new QuickSort();
		qs.sort(ra3, 0, ra3.length - 1);
		endTime = System.nanoTime();
		long quickSortTime = (endTime - startTime);

		// execute bubbleSort and time
		int[] ra4 = new int[size];
		System.arraycopy(randomArray, 0, ra4, 0, randomArray.length);
		startTime = System.nanoTime();
		ra4 = bubbleSort(ra4);
		endTime = System.nanoTime();
		long bubbleSortTime = (endTime - startTime);

		reportResults(mergeSortTime, selectionSortTime, quickSortTime, bubbleSortTime);
	}

	public static void reportResults(long ms, long ss, long qs, long bs) {
		System.out.println("~~~~~~~~~~RESULTS~~~~~~~~~~");
		System.out.println("<Algorithm>       <Runtime>");
		System.out.println("MergeSort         " + ms);
		System.out.println("QuickSort         " + qs);
		System.out.println("SelectionSort     " + ss);
		System.out.println("BubbleSort        " + bs);
	}

	public static int[] randomArrayGenerator(int size) {
		int[] randomArray = new int[size];

		// fill an arraylist with random numbers 0..size and shuffle
		ArrayList<Integer> arr = new ArrayList<>(size);
		for (int i = 0; i < size; i++) {
		    arr.add(i);
		}
		Collections.shuffle(arr);

		// convert arraylist to int array
		for (int i = 0; i < size; i++) {
			randomArray[i] = arr.get(i);
		}

		return randomArray;
	}

	public static void mergeSort(int[] array, int left, int right) {
		if (left < right) {
			int middle = (left + right) / 2;

			mergeSort(array, left, middle);
			mergeSort(array, middle + 1, right);

			merge(array, left, middle, right);
		}
	}

	public static void merge(int[] array, int low, int middle, int high) {

	}

	public static int[] selectionSort(int[] array) {
		int size = array.length;

		for (int i = 0; i < size - 1; i++) {
			int minIdx = i;
			for (int j = i + 1; j < size; j++) {
				if (array[j] < array[minIdx]) {
					minIdx = j;
				}
			}

			int temp = array[minIdx];
			array[minIdx] = array[i];
			array[i] = temp;
		}

		return array;
	}

	public static int[] quickSort(int[] array) {
		return null;

	}

	public static int[] bubbleSort(int[] array) {
		int size = array.length;

		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}

		return array;
	}
}