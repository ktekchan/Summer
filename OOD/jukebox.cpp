/*
 * Khushboo Tekchandani
 * OOD for a jukebox.
 * Assumptions:
 *    1. Computer Simulation. Contains only songs.
 *    2. Does not require currency
 *    3. Possible features: Make playlist and modify, queue songs, play song
 *       User information
 */

#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

class Song{

   protected:
      long id;
      string title;
      string artist;
   public:
      Song(long id_, string title_, string artist_) : id(id_), title(title_),
         artist(artist_) {};
      long getSid() {return id;};
      string getTitle() {return title;};
      string getArtitst() {return artist;};

      void setSid(long id) {this->id = id;};
      void setTitle(string title) {this->title = title;};
      void setArtist(string artist) {this->artist = artist;};
};

class User{

   protected:
      long uid;
      string name;
   public:
      User(long id_, string name_) : uid(id_), name(name_){};
      long getUid() {return uid;};
      string getName() {return name;};

      void setUid(long uid) {this->uid = uid;};
      void setName(string name) {this->name = name;};
};

class Playlist{

   protected:
      string playlistName;
      Song *current;
      queue<Song*> q;
   public:
      Playlist(string name, Song *s, queue<Song*> sq) : playlistName(name), 
         current(s), q(sq) {};

      void addSong (Song *s) {q.push(s);};
      Song* nextSong () {return q.front();};
      Song* getCurrent() {return this->current;};
};

class Jukebox{

   protected:
      set<Song*> songrepo;
      User user;
      Playlist *current;
   public:
      Jukebox(set<Song*> songs, User user_, Playlist *p) : songrepo(songs), 
         user(user_), current(p) {};

      //getters and setters// -- haven't written

      Playlist *create (); // create new playlist and set it as current
};
