// --- Iterator Interface ---
interface PlaylistIteratorInterface {
    hasNext(): boolean;
    next(): string;
    reset(): void;
}

// --- Forward Iterator ---
class PlaylistIterator implements PlaylistIteratorInterface {
    private playlist: Playlist;
    private index: number = 0;

    constructor(playlist: Playlist) {
        this.playlist = playlist;
    }

    hasNext(): boolean {
        return this.index < this.playlist.size();
    }

    next(): string {
        if (this.hasNext()) {
            return this.playlist.getSongs()[this.index++];
        }
        return "";
    }

    reset(): void {
        this.index = 0;
    }
}

// --- Reverse Iterator ---
class ReversePlaylistIterator implements PlaylistIteratorInterface {
    private playlist: Playlist;
    private index: number;

    constructor(playlist: Playlist) {
        this.playlist = playlist;
        this.index = playlist.size() - 1;
    }

    hasNext(): boolean {
        return this.index >= 0;
    }

    next(): string {
        if (this.hasNext()) {
            return this.playlist.getSongs()[this.index--];
        }
        return "";
    }

    reset(): void {
        this.index = this.playlist.size() - 1;
    }
}

// --- Collection: Playlist ---
class Playlist {
    private songs: string[] = [];

    addSong(song: string): void {
        this.songs.push(song);
    }

    getSongs(): string[] {
        return this.songs;
    }

    iterator(): PlaylistIteratorInterface {
        return new PlaylistIterator(this);
    }

    reverseIterator(): PlaylistIteratorInterface {
        return new ReversePlaylistIterator(this);
    }

    size(): number {
        return this.songs.length;
    }
}

// --- Main ---
const playlist = new Playlist();
playlist.addSong("Shape of You");
playlist.addSong("Bohemian Rhapsody");
playlist.addSong("Blinding Lights");
playlist.addSong("Imagine");
playlist.addSong("Hotel California");

console.log("=== Forward Iteration ===");
const forward = playlist.iterator();
while (forward.hasNext()) {
    console.log("  " + forward.next());
}

console.log("\n=== Reverse Iteration ===");
const reverse = playlist.reverseIterator();
while (reverse.hasNext()) {
    console.log("  " + reverse.next());
}

console.log("\n=== Multiple Iterations ===");
forward.reset();
console.log("First Song (Forward): " + forward.next());

reverse.reset();
console.log("First Song (Reverse): " + reverse.next());
