import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays; 
import java.lang.String;
import java.lang.Integer;

class MUTunes {
    public static void main(String[] args) throws FileNotFoundException {
        
        int[] song_lengths = new int[1];
        String[] song_titles = new String[1];
        String[] song_artists = new String[1];
        int j = 0;
        int noOfSongs = 0;
        try{
            File myFile = new File("Music.txt");
            Scanner input = new Scanner(myFile);
            noOfSongs = input.nextInt();
            song_lengths = new int[noOfSongs];
            song_titles = new String[noOfSongs];
            song_artists = new String[noOfSongs];
            input.nextLine();
            int i = 0;
            while (input.hasNextLine()) {
                String data = input.nextLine();
                String[] parts = data.split (":");
                song_lengths[i] = Integer.parseInt(parts[0]);
                song_artists[i] = parts[2];
                song_titles[i] = parts[1];
                i=i+1;
            }
            input.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        System.out.printf("%-24s %-24s %4s","TITLE","ARTIST","TIME");
        System.out.println();
        System.out.printf("%-24s %-24s %4s","-----","------","----");
        
        for(j=0;j<noOfSongs;j++){
            printTable(song_titles,song_artists,song_lengths,j);
        }

        System.out.println();
        System.out.println();
        System.out.printf("%-24s %-24s %4s","TOTAL TIME","", getTotalTime(song_lengths));
        
        System.out.println();
        System.out.println();
        
        System.out.printf("%-24s","LONGEST SONG");
        System.out.println();
        System.out.printf("%-24s","------------");
        int longestSong = longestSongIndex(song_titles, song_artists, song_lengths);
        printTable(song_titles,song_artists,song_lengths,longestSong);
        System.out.println();
        System.out.println();

        System.out.printf("%-24s","SHORTEST SONG");
        System.out.println();
        System.out.printf("%-24s","-------------");
        int shortestSong = shortestSongIndex(song_titles, song_artists, song_lengths);
        printTable(song_titles,song_artists,song_lengths,shortestSong);
        System.out.println();
        System.out.println();

        System.out.printf("%-24s","SONGS");
        System.out.println();
        System.out.printf("%-24s","-----");
        printSong(song_titles);
}
    public static void printTable(String[] song_title, String[] song_artist, int[] song_length, int n) {
        System.out.println();
        System.out.printf("%-24s %-24s %4s",song_title[n],song_artist[n],String.format("%d",song_length[n]));
    }

    public static void printSong(String[] song_titles) {
        int i =0;
        Arrays.sort(song_titles);
        for(i=0;i<song_titles.length;i++){
            System.out.println();
            System.out.printf("%-24s",song_titles[i]);
        }
    }

    public static int getTotalTime(int[] song_lengths) {
        int i=0, total_time=0;
        for(i=0;i<song_lengths.length;i++){
            total_time = total_time + song_lengths[i];
        }        
        return total_time;
    }

    public static int longestSongIndex(String[] song_title, String[] song_artist, int[] song_length) {
        int i = 0, longest = 0, pos = 0;
        longest = song_length[0];
        for(i=0;i<song_length.length;i++){
            if(longest < song_length[i]){
                longest = song_length[i];
                pos = i;
            }
        }       
        return pos;
    }

    public static int shortestSongIndex(String[] song_title, String[] song_artist, int[] song_length) {
        int i = 0, shortest = 0, pos = 0;
        shortest = song_length[0];
        for(i=0;i<song_length.length;i++){
            if(shortest > song_length[i]){
                shortest = song_length[i];
                pos = i;
            }
        }       
        return pos;
    }
}