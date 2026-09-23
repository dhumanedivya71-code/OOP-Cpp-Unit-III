#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Base Class
class Media {
protected:
    string title;
    string fileName;

public:
    Media(string t, string f)
        : title(t), fileName(f) {}

    virtual void play() const = 0;

    virtual void pause() const = 0;

    virtual void stop() const = 0;

    virtual void showDetails() const = 0;

    virtual ~Media() = default;
};


// Derived Class: Audio
class Audio : public Media {
private:
    string artist;

public:
    Audio(string t, string f, string a)
        : Media(t, f), artist(a) {}

    void play() const override {
        cout << "Playing audio: "
             << title << endl;
    }

    void pause() const override {
        cout << "Audio paused: "
             << title << endl;
    }

    void stop() const override {
        cout << "Audio stopped: "
             << title << endl;
    }

    void showDetails() const override {
        cout << "\n--- Audio Details ---" << endl;
        cout << "Title: " << title << endl;
        cout << "File: " << fileName << endl;
        cout << "Artist: " << artist << endl;
    }
};


// Derived Class: Video
class Video : public Media {
private:
    string resolution;

public:
    Video(string t, string f, string r)
        : Media(t, f), resolution(r) {}

    void play() const override {
        cout << "Playing video: "
             << title << endl;
    }

    void pause() const override {
        cout << "Video paused: "
             << title << endl;
    }

    void stop() const override {
        cout << "Video stopped: "
             << title << endl;
    }

    void showDetails() const override {
        cout << "\n--- Video Details ---" << endl;
        cout << "Title: " << title << endl;
        cout << "File: " << fileName << endl;
        cout << "Resolution: " << resolution << endl;
    }
};


// Derived Class: Image
class Image : public Media {
private:
    string format;

public:
    Image(string t, string f, string fmt)
        : Media(t, f), format(fmt) {}

    void play() const override {
        cout << "Displaying image: "
             << title << endl;
    }

    void pause() const override {
        cout << "Image pause operation: "
             << title << endl;
    }

    void stop() const override {
        cout << "Image display stopped: "
             << title << endl;
    }

    void showDetails() const override {
        cout << "\n--- Image Details ---" << endl;
        cout << "Title: " << title << endl;
        cout << "File: " << fileName << endl;
        cout << "Format: " << format << endl;
    }
};


// Main Function
int main() {

    vector<unique_ptr<Media>> mediaItems;

    mediaItems.push_back(
        make_unique<Audio>(
            "Tum Hi Ho",
            "tum_hi_ho.mp3",
            "Arijit Singh"
        )
    );

    mediaItems.push_back(
        make_unique<Video>(
            "C++ Tutorial",
            "cpp_tutorial.mp4",
            "1080p"
        )
    );

    mediaItems.push_back(
        make_unique<Image>(
            "College Event",
            "college_event.jpg",
            "JPEG"
        )
    );

    cout << "====================================" << endl;
    cout << "       MEDIA PLAYER SYSTEM" << endl;
    cout << "====================================" << endl;

    for (const auto& media : mediaItems) {

        media->showDetails();

        cout << endl;

        media->play();

        media->pause();

        media->stop();

        cout << "------------------------------------"
             << endl;
    }

    return 0;
}
