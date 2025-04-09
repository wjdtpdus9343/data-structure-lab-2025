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
    // ������
    Music(string t, string a, string al, int y)
        : title(t), artist(a), album(al), year(y) {}

    // �⺻ ������ (�� �� ���� �� ���)
    Music() : title(""), artist(""), album(""), year(0) {}

    // Getter �Լ���
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
    // ������
    MusicStreamingService(string service_name) {
        this->service_name = service_name;
    }

    // ���� �߰� ���
    void addMusic(string title, string artist, string album, int year) {
        Music new_music(title, artist, album, year);
        music_list.push_back(new_music);
        cout << title << " by " << artist << " added to " << service_name << endl;
    }

    // ��ü ���� ��� ���
    void showAllMusic() const {
        cout << "===== Music List in " << service_name << " =====" << endl;
        for (const auto& m : music_list) {
            cout << m.getTitle() << " - " << m.getArtist()
                 << " (" << m.getAlbum() << ", " << m.getYear() << ")" << endl;
        }
    }

    // ���� ã���ִ� ���� (Title)
    Music* searchByTitle(string title) {
        for(int i = 0 ; i < music_list.size() ; i++) {
            if (music_list[i].getTitle() == title) {
                return &music_list[i];
            }
        }
        return NULL;
    }

    // ���� ã���ִ� ���� (Artist)


};
