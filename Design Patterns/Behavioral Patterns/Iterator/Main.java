import java.util.*;

// --- Given classes (do not modify) ---

class Playlist {
    private List<String> songs = new ArrayList<>();

    public void addSong(String song) {
        songs.add(song);
    }

    public List<String> getSongs() {
        return songs;
    }
}

// --- Implement the class below ---

class ReversePlaylistIterator implements Iterator<String> {
    // TODO: Store reference to Playlist and current index
    // TODO: Constructor initializes index to last position
    private List<String> songs;
    private int index = 0;

    public ReversePlaylistIterator(Playlist playlist){
        this.songs = playlist.getSongs();
        this.index = songs.size() - 1;
    }

    @Override
    public boolean hasNext() {
        // TODO: Return true if there are elements before current position
        return index >= 0;
    }

    @Override
    public String next() {
        // TODO: Return current element and move backward
        String current = this.songs.get(index);
        index--;
        return current;
    }
}

public class Main {
    public static void main(String[] args) {
        Playlist playlist = new Playlist();
        playlist.addSong("Shape of You");
        playlist.addSong("Bohemian Rhapsody");
        playlist.addSong("Blinding Lights");
        
        ReversePlaylistIterator reverse = new ReversePlaylistIterator(playlist);
        System.out.println("Reverse Playlist:");
        while (reverse.hasNext()) {
            System.out.println("  " + reverse.next());
        }
    }
}