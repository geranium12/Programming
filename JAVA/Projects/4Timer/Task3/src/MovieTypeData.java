public class MovieTypeData {
    private String movieType;
    long value;

    public MovieTypeData(String movieType, long value) {
        this.movieType = movieType;
        this.value = value;
    }

    public String getMovieType() {
        return movieType;
    }

    public void setMovieType(String movieType) {
        this.movieType = movieType;
    }

    public long getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
