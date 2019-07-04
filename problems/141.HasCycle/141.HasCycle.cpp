﻿// 141.HasCycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\ListNode.h"
using namespace std;

bool hasCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL) return false;
		slow = slow->next;
		fast = fast->next;

		if (slow == fast) return true;
	}
	return false;
}

void Init(ListNode **pHead)
{
	const int cLinkListLen = 3;

	ListNode *pNode = NULL;
	ListNode *pNodeNew = NULL;

	for (int i = 0; i < cLinkListLen; i++)
	{
		pNodeNew = new ListNode(cLinkListLen - i);
		pNodeNew->next = pNode;
		pNode = pNodeNew;
	}

	pNodeNew = new ListNode(cLinkListLen + 1);
	pNodeNew->next = pNode;
	pNode = pNodeNew;

	for (int i = 0; i < cLinkListLen; i++)
	{
		pNodeNew = new ListNode(i + 1);
		pNodeNew->next = pNode;
		pNode = pNodeNew;
	}

	*pHead = pNode;
}

int main()
{
	ListNode *pHead = NULL;
	Init(&pHead);
	PrintCycleLinkList(pHead);

	//for (int i = 1; i < 2; i++)
	{
		cout << hasCycle(pHead) << endl;
		cout << endl;
	}
}