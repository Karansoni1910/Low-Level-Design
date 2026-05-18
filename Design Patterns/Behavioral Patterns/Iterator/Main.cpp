#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// --- Iterator Interface ---
template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual void reset() = 0;
};

// --- Forward Declaration ---
class Playlist;

// --- Forward Iterator ---
class PlaylistIterator : public Iterator<string> {
private:
    const Playlist* playlist;
    int index;

public:
    PlaylistIterator(const Playlist* playlist);
    bool hasNext() const override;
    string next() override;
    void reset() override;
};

// --- Reverse Iterator ---
class ReversePlaylistIterator : public Iterator<string> {
private:
    const Playlist* playlist;
    int index;

public:
    ReversePlaylistIterator(const Playlist* playlist);
    bool hasNext() const override;
    string next() override;
    void reset() override;
};

// --- Collection: Playlist ---
class Playlist {
private:
    vector<string> songs;

public:
    void addSong(const string& song) {
        songs.push_back(song);
    }

    const vector<string>& getSongs() const {
        return songs;
    }

    shared_ptr<Iterator<string>> iterator() const {
        return make_shared<PlaylistIterator>(this);
    }

    shared_ptr<Iterator<string>> reverseIterator() const {
        return make_shared<ReversePlaylistIterator>(this);
    }

    int size() const {
        return songs.size();
    }
};

// --- PlaylistIterator Implementation ---
PlaylistIterator::PlaylistIterator(const Playlist* playlist)
    : playlist(playlist), index(0) {}

bool PlaylistIterator::hasNext() const {
    return index < playlist->size();
}

string PlaylistIterator::next() {
    if (hasNext()) {
        return playlist->getSongs()[index++];
    }
    return "";
}

void PlaylistIterator::reset() {
    index = 0;
}

// --- ReversePlaylistIterator Implementation ---
ReversePlaylistIterator::ReversePlaylistIterator(const Playlist* playlist)
    : playlist(playlist), index(playlist->size() - 1) {}

bool ReversePlaylistIterator::hasNext() const {
    return index >= 0;
}

string ReversePlaylistIterator::next() {
    if (hasNext()) {
        return playlist->getSongs()[index--];
    }
    return "";
}

void ReversePlaylistIterator::reset() {
    index = playlist->size() - 1;
}

// --- Main ---
int main() {
    Playlist playlist;
    playlist.addSong("Shape of You");
    playlist.addSong("Bohemian Rhapsody");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Imagine");
    playlist.addSong("Hotel California");

    cout << "=== Forward Iteration ===" << endl;
    auto forward = playlist.iterator();
    while (forward->hasNext()) {
        cout << "  " << forward->next() << endl;
    }

    cout << "\n=== Reverse Iteration ===" << endl;
    auto reverse = playlist.reverseIterator();
    while (reverse->hasNext()) {
        cout << "  " << reverse->next() << endl;
    }

    cout << "\n=== Multiple Iterations ===" << endl;
    forward->reset();
    cout << "First Song (Forward): " << forward->next() << endl;

    reverse->reset();
    cout << "First Song (Reverse): " << reverse->next() << endl;

    return 0;
}
