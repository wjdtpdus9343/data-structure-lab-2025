#pragma once
//
#include <iostream>
//
#include <string>
//
#include <vector>

//
using namespace std;


class Music {
private:
	string title;
	string artist;
	string album;
	int year;

public:
	//������
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}
};


class MusicStreamingService {
	//���� ã���ִ� ����
};