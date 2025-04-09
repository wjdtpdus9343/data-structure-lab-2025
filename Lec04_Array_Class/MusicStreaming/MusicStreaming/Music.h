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
    // 생성자
    Music(string t, string a, string al, int y)
        : title(t), artist(a), album(al), year(y) {}

    // 기본 생성자 (빈 값 삽입 시 사용)
    Music() : title(""), artist(""), album(""), year(0) {}

    // Getter 함수들
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    string getAlbum() const { return album; }
    int getYear() const { return year; }
};

class MusicStreamingService {
private:
    string service_name;
    vector<Music> music_list;

public:
    // 생성자
    MusicStreamingService(string service_name) {
        this->service_name = service_name;
    }

    // 음악 추가 기능
    void addMusic(string title, string artist, string album, int year) {
        Music new_music(title, artist, album, year);
        music_list.push_back(new_music);
        cout << title << " by " << artist << " added to " << service_name << endl;
    }

    // 전체 음악 목록 출력
    void showAllMusic() const {
        cout << "===== Music List in " << service_name << " =====" << endl;
        for (const auto& m : music_list) {
            cout << m.getTitle() << " - " << m.getArtist()
                 << " (" << m.getAlbum() << ", " << m.getYear() << ")" << endl;
        }
    }

    // 음악 찾아주는 서비스 (Title)
    Music* searchByTitle(string title) {
        for(int i = 0 ; i < music_list.size() ; i++) {
            if (music_list[i].getTitle() == title) {
                return &music_list[i];
            }
        }
        return NULL;
    }

    // 음악 찾아주는 서비스 (Artist)


};
