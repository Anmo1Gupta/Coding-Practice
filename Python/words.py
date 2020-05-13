#! C:/Users/Aa/AppData/Local/Programs/Python/Python38-32/python.exe python3
# ^ is a shebang
from urllib.request import urlopen
import sys
# story = urlopen('http://sixty-north.com/c/t.txt')
# story_words = []
# for line in story:
#     #     line_words = line.split()
#     line_words = line.decode('utf-8').split()
#     for word in line_words:
#         story_words.append(word)

# story.close()

# for word in story_words:
#     print(word)
def fetch_words(url):
    # story = urlopen('http://sixty-north.com/c/t.txt')
    """ 
    DOCSTRINGS FOR PYTHON
     (Description) ...

     Args: ...

     Returns: ...
    """
    story = urlopen(url)
    story_words = []
    for line in story:
        #     line_words = line.split()
        line_words = line.decode('utf-8').split()
        for word in line_words:
            story_words.append(word)

    story.close()

    # for word in story_words:
    #     print(word)
    return story_words


# print(__name__)

# if __name__ == "__main__":
#     fetch_words()

def print_items(items):
    for item in items:
        print(item)

# def main():
#     url = sys.argv[1]
#     words = fetch_words(url)
#     print_items(words)

# if __name__ == "__main__":
#     main()

def main(url):  
    words = fetch_words(url)
    print_items(words)

if __name__ == "__main__":
    main(sys.argv[1])
