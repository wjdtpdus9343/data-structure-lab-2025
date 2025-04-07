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
	//생성자
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}
};


class MusicStreamingService {
	//음악 찾아주는 서비스
};