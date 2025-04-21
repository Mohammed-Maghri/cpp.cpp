/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:03:27 by mmaghri           #+#    #+#             */
/*   Updated: 2024/12/02 19:27:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

void merged(std::deque<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<int> leftArray(n1);
    std::deque<int> rightArray(n2);
    for (int i = 0; i < n1; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++){
        rightArray[j] = array[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSortd(std::deque<int>& array, int left, int right, int flag) {
    static int count = 0;
    (void)flag;
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortd(array, left, mid, 0);
        mergeSortd(array, mid + 1, right, -1);
        merged(array, left, mid, right);
        count++;
    }
}

void merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for (int i = 0; i < n1; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++){
        rightArray[j] = array[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSort(std::vector<int>& array, int left, int right, int flag) {
    static int count = 0;
    (void)flag;
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid, 0);
        mergeSort(array, mid + 1, right, -1);
        merge(array, left, mid, right);
        count++;
    }
}
