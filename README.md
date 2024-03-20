# Sentiment Analysis
This project performs sentiment analysis on text input to determine whether the sentiment expressed is positive, negative, or neutral. Sentiment analysis is a natural language processing technique used to understand the underlying sentiment or mood in a piece of text. 

## Overview
The sentiment analysis algorithm analyzes the input text by tokenizing it into individual words and comparing each word against predefined lists of positive, negative, and neutral words. Additionally, the algorithm checks for negation words to adjust the sentiment accordingly. However, in this code we haven't use any machine learning techniques we simply use tokenization method for better searching capabilities for the keywords in the input string.

## Usage
To use the sentiment analysis tool:

- Input the text you want to analyze.
- The tool will output whether the sentiment of the text is positive, negative, or neutral.
## Features
- Case-insensitive comparison for accurate sentiment analysis.
- Supports various positive, negative, and neutral words for comprehensive sentiment detection.
- Handles negation words to account for context in sentiment analysis.

## Explanation
Let's break down each part of the code:

```cpp
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Define arrays for positive, negative, neutral, and negation words
    const vector<string> positiveWords = { /* ... positive words ... */ };
    const vector<string> negativeWords = { /* ... negative words ... */ };
    const vector<string> neutralWords = { /* ... neutral words ... */ };
    const vector<string> negationWords = { /* ... negation words ... */ };

    // Get user input
    cout << "Enter the text for sentiment analysis: ";
    string inputText;
    getline(cin, inputText);

    // Standardize to lowercase for consistent comparison
    transform(inputText.begin(), inputText.end(), inputText.begin(), ::tolower);

    // Tokenize input text
    istringstream iss(inputText);
    string word;

    // Initialize counters
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

    // Loop through each word in the input text
    while (iss >> word) {
        // Check for negation
        bool isNegation = (find(negationWords.begin(), negationWords.end(), word) != negationWords.end());

        // Check if the word is in positive, negative, or neutral sets
        if (find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end()) {
            positiveCount += (isNegation) ? -1 : 1;
        } else if (find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end()) {
            negativeCount += (isNegation) ? -1 : 1;
        } else if (find(neutralWords.begin(), neutralWords.end(), word) != neutralWords.end()) {
            neutralCount += (isNegation) ? -1 : 1;
        }
    }

    // Determine sentiment based on word occurrences
    string sentiment;
    if (positiveCount > negativeCount && positiveCount > neutralCount) {
        sentiment = "Positive";
    } else if (negativeCount > positiveCount && negativeCount > neutralCount) {
        sentiment = "Negative";
    } else {
        sentiment = "Neutral";
    }

    // Display result
    cout << "Sentiment: " << sentiment << "\n";

    return 0;
}
```

Here's a step-by-step explanation:

1. **Header Inclusions:**
   - `#include <iostream>`: Provides input and output stream functionality.
   - `#include <sstream>`: Allows string stream functionality.
   - `#include <algorithm>`: Provides algorithms for operations on sequences.
   - `#include <vector>`: Defines the vector container.

2. **Namespace Declaration:**
   - `using namespace std;`: Allows the use of elements from the `std` (Standard Library) namespace without explicit qualification.

3. **Main Function:**
   - `int main() { /* ... */ }`: The main function, where the program execution begins.

4. **Word Lists:**
   - `const vector<string> positiveWords = { /* ... positive words ... */ };`: A vector containing positive words.
   - `const vector<string> negativeWords = { /* ... negative words ... */ };`: A vector containing negative words.
   - `const vector<string> neutralWords = { /* ... neutral words ... */ };`: A vector containing neutral words.
   - `const vector<string> negationWords = { /* ... negation words ... */ };`: A vector containing negation words.

5. **User Input:**
   - `cout << "Enter the text for sentiment analysis: ";`: Displays a prompt to the user.
   - `string inputText; getline(cin, inputText);`: Reads a line of text entered by the user.

6. **Text Standardization:**
   - `transform(inputText.begin(), inputText.end(), inputText.begin(), ::tolower);`: Converts the input text to lowercase for consistent comparison.

7. **Tokenization and Sentiment Analysis:**
   - `istringstream iss(inputText);`: Creates a string stream for tokenizing the input text.
   - `string word;`: Declares a string variable to store each token.
   - `int positiveCount = 0, negativeCount = 0, neutralCount = 0;`: Initializes counters for positive, negative, and neutral words.
   - The `while` loop tokenizes the input text and checks each word against the positive, negative, and neutral word lists. It also checks for negation.
   - Updates the positive, negative, and neutral counts based on the presence of words and negations.

8. **Sentiment Determination:**
   - `string sentiment;`: Declares a string variable to store the final sentiment.
   - Determines the sentiment (positive, negative, or neutral) based on the counts of positive, negative, and neutral words.

9. **Display Result:**
   - `cout << "Sentiment: " << sentiment << "\n";`: Displays the determined sentiment.

10. **Return Statement:**
   - `return 0;`: Indicates successful execution of the program.

The program essentially takes user input, analyzes the sentiment of the input text based on predefined word lists, and then outputs whether the sentiment is positive, negative, or neutral.

|Sentiments             | No. of Keywords                                                              |
| ----------------- | ------------------------------------------------------------------ |
| Positive | ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ 416  |
| Negative |‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎217 |
| Neutral |‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ 195  |
| Negation |‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ 143 |


## License


[![Apache License](https://img.shields.io/github/license/umair3984/Sentiment-Analysis
)](https://github.com/apache/.github/blob/main/LICENSE)


## Author
![Logo](https://scontent.fkhi16-1.fna.fbcdn.net/v/t39.30808-1/366299798_313247964423566_8941155358383713367_n.jpg?stp=dst-jpg_p320x320&_nc_cat=107&ccb=1-7&_nc_sid=5f2048&_nc_ohc=5IEeHuTosQ8AX9e7DfZ&_nc_ht=scontent.fkhi16-1.fna&oh=00_AfBmgrjAHFf9H8D5HbtTdRogh5qDWiR9QfyvEcM5g9WidA&oe=65FFEE35)


- [Muhammad Umair Qureshi](https://github.com/umair3984)


## Used By

This project was used for the Open-Ended Lab held at Department of Electronics Engineering at NED University of Engineering & Technology 

© [Muhammad Umair Qureshi](https://github.com/umair3984) holds all rights to the project


