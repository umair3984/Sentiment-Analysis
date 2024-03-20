#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Define arrays for positive, negative, neutral, and negation words
    const vector<string> positiveWords = {
"alright","mashallah","inshallah","alhamdulliah","positive","happier","happiest", "happy", "joyful", "delightful", "cheerful",
          "blissful", "ecstatic", "radiant", "grateful", "magnificent", "excellent", "wonderful",
          "amazing", "thriving", "prosperous", "successful", "accomplished", "triumphant", "glorious",
"fantastic", "splendid", "fabulous", "superb", "outstanding", "stellar", "first-rate", "terrific", "marvelous", "fantastic", "extraordinary",
 "brilliant", "superior", "splendiferous", "phenomenal", "remarkable", "awesome", "inspiring", "upbeat", "affirmative", "constructive",
 "encouraging", "hopeful", "buoyant", "jubilant", "high-spirited", "heartwarming", "love", "better", "good", "great","joyful", "exuberant",
 "optimistic", "vibrant", "uplifting", "delightful", "cheerful", "blissful", "ecstatic", "radiant", "grateful", "magnificent", "excellent",
  "wonderful", "amazing", "thriving", "prosperous", "successful", "accomplished", "triumphant", "glorious", "fantastic", "splendid",
  "fabulous", "superb", "outstanding", "stellar", "first-rate", "terrific", "marvelous", "fantastic", "extraordinary", "brilliant",
   "superior", "splendiferous", "phenomenal", "remarkable", "awesome", "inspiring", "upbeat", "positive", "affirmative", "constructive",
   "encouraging", "hopeful", "buoyant", "jubilant", "high-spirited", "heartwarming", "pleasurable", "enjoyable", "satisfying", "fulfilling",
    "uplifting", "refreshing", "rejuvenating", "energizing", "revitalizing", "inspiring", "motivating", "invigorating", "empowering",
     "enthusiastic", "dynamic", "passionate", "dynamic", "radiant", "bright", "shining", "golden", "serene", "tranquil", "peaceful",
      "calm", "soothing", "gentle", "graceful", "lovely", "charming", "captivating", "appealing", "attractive", "beautiful", "gorgeous",
      "stunning", "breathtaking", "majestic", "grand", "elegant", "stylish", "sophisticated", "classy", "graceful", "dazzling", "sparkling",
       "glittering", "lively", "animated", "vibrant", "dynamic", "exciting", "spirited", "effervescent", "lighthearted", "playful",
        "fun-loving", "entertaining", "joyous", "festive", "celebratory", "lively", "vivacious", "dynamic", "vital", "alive", "vigorous",
         "robust", "resilient", "sturdy", "powerful", "strong", "healthy", "thriving", "wholesome", "fit", "active", "energetic",
          "dynamic", "resolute", "determined", "persistent", "persevering", "dedicated", "committed", "unwavering", "indomitable",
           "strong-willed", "courageous", "brave", "fearless", "adventurous", "bold", "daring", "audacious", "intrepid", "valiant",
           "gallant", "heroic", "noble", "magnanimous", "generous", "charitable", "altruistic", "benevolent", "kindhearted",
           "compassionate", "empathetic", "sympathetic", "caring", "loving", "affectionate", "tender", "warmhearted", "friendly",
            "amiable", "pleasant", "agreeable", "considerate", "thoughtful", "courteous", "polite", "respectful", "gracious", "gentle",
             "kind", "honest", "truthful", "sincere", "genuine", "authentic", "reliable", "dependable", "trustworthy", "loyal", "faithful",
             "dedicated", "devoted", "steadfast", "unswerving", "consistent", "persistent", "tenacious", "diligent", "industrious",
             "hardworking", "productive", "efficient", "effective", "skillful", "talented", "creative", "innovative", "resourceful",
              "clever", "smart", "intelligent", "wise", "knowledgeable", "insightful", "perceptive", "discerning", "astute", "sharp",
               "brilliant", "genius", "gifted", "talented", "skilled", "proficient", "competent", "capable", "adept", "masterful",
               "expert", "excellent", "superior", "outstanding", "stellar", "accomplished", "successful", "prosperous", "triumphant",
                "victorious", "triumphant", "victorious", "congratulatory", "applauding", "appreciative", "grateful", "thankful",
                "pleased", "satisfied", "content", "fulfilled", "joyful", "ecstatic", "blissful", "exuberant", "radiant", "upbeat",
                "cheerful", "buoyant", "jubilant", "lighthearted", "playful", "festive", "celebratory", "positive", "optimistic",
                 "hopeful", "inspiring", "motivating", "uplifting", "encouraging", "empowering", "refreshing", "energizing", "revitalizing",
"dynamic", "vibrant", "alive", "lively", "active", "resilient", "strong", "robust", "healthy", "thriving", "wholesome", "fit",
"courageous", "brave", "fearless", "adventurous", "bold", "daring", "intrepid", "valiant", "heroic", "noble", "generous", "charitable",
 "altruistic", "benevolent", "kindhearted", "compassionate", "empathetic", "sympathetic", "loving", "affectionate", "tender",
  "warmhearted", "friendly", "amiable", "pleasant", "agreeable", "considerate", "thoughtful", "great","better","best","good" };
    const vector<string> negativeWords = { "negative", "negate", "negated", "negating", "negates",
"unhappy", "unhappiness","not",
"sad", "sadden", "saddened", "saddening", "saddens",
"disappoint", "disappointed", "disappointing", "disappointment", "disappoints",
"frustrate", "frustrated", "frustrating", "frustration", "frustrates",
"dishearten", "disheartened", "disheartening", "disheartenment", "disheartens",
"discourage", "discouraged", "discouraging", "discouragement", "discourages",
"dismal",
"miserable", "miserably",
"unfortunate", "unfortunately",
"gloomy", "gloom",
"grim", "grimly",
"bleak", "bleakly",
"trouble", "troubled", "troubling", "troubles",
"difficult", "difficulty",
"challenge", "challenging", "challenges",
"problem", "problematic", "problems",
"inferior", "inferiority",
"poor", "poorly",
"bad", "badly",
"terrible", "terribly",
"awful", "awfully",
"horrible", "horribly",
"dreadful", "dreadfully",
"abysmal", "abysmally",
"lousy", "lousily",
"pitiful", "pitifully",
"unfavorable",
"unpleasant", "unpleasantly",
"displease", "displeased", "displeasing", "displeasure", "displeases",
"annoy", "annoyed", "annoying", "annoyance", "annoys",
"irritate", "irritated", "irritating", "irritation", "irritates",
"upset", "upsetting", "upsets",
"offend", "offensive", "offends",
"distress", "distressing", "distressed",
"hurt", "hurtful", "hurts",
"pain", "painful", "painfully",
"heartbreak", "heartbreaking", "heartbreaks",
"regret", "regrettable", "regrettably",
"tragic", "tragically",
"catastrophe", "catastrophic",
"devastate", "devastating", "devastation", "devastates",
"destroy", "destructive", "destruction", "destroys",
"damage", "damaging", "damages",
"worry", "worrying", "worries",
"concern", "concerning", "concerns",
"negative",
"detriment", "detrimental",
"harm", "harmful", "harmfully",
"hostile", "hostility",
"unfavorable",
"unpleasant", "unpleasantly",
"hostile", "hostility",
"bitter", "bitterness",
"angry", "anger",
"displease", "displeased", "displeasing", "displeasure", "displeases",
"disgruntle", "disgruntled", "disgruntling",
"resent", "resentful", "resenting", "resentment", "resents",
"agitate", "agitated", "agitating", "agitation", "agitates",
"irritate", "irritated", "irritating", "irritation", "irritates",
"frustrate", "frustrated", "frustrating", "frustration", "frustrates",
"anger", "angry",
"hate", "hateful", "hatred",
"hostile", "hostility",
"resent", "resentful", "resentment",
"aggress", "aggressive", "aggressiveness",
"vindicate", "vindictive", "vindictiveness", "vindicates",
"malice", "malicious", "maliciously",
"defeat", "defeated", "defeating", "defeats"
"hate", "terrible", "awful" };
    const vector<string> neutralWords = { "Agree", "Arrive", "Aware", "Balance", "Begin", "Calculate", "Calm", "Cancel", "Capture", "Change",
    "Clear", "Combine", "Compare", "Compose", "Connect", "Consider", "Continue", "Contribute", "Cooperate", "Correct",
    "Create", "Decide", "Define", "Demand", "Describe", "Design", "Develop", "Differentiate", "Discover", "Display",
    "Distribute", "Document", "Download", "Earn", "Edit", "Eliminate", "Emphasize", "Enable", "Encourage", "Ensure",
    "Establish", "Estimate", "Evaluate", "Examine", "Expand", "Explain", "Explore", "Express", "Extract", "Facilitate",
    "Feature", "Formulate", "Generate", "Guide", "Highlight", "Identify", "Illustrate", "Implement", "Improve", "Include",
    "Incorporate", "Increase", "Indicate", "Inform", "Initiate", "Innovate", "Inspect", "Install", "Integrate", "Interpret",
    "Introduce", "Investigate", "Join", "Judge", "Justify", "Keep", "Know", "Learn", "Locate", "Maintain", "Manage",
    "Measure", "Merge", "Monitor", "Motivate", "Navigate", "Negotiate", "Observe", "Obtain", "Operate", "Organize",
    "Outline", "Overcome", "Perform", "Plan", "Predict", "Prepare", "Present", "Prioritize", "Process", "Produce",
    "Progress", "Promote", "Propose", "Protect", "Provide", "Pursue", "Qualify", "Question", "Quote", "Reach", "Recognize",
    "Recommend", "Recover", "Recruit", "Reflect", "Refine", "Refresh", "Regulate", "Reinforce", "Reject", "Relate",
    "Release", "Reorganize", "Repair", "Replace", "Represent", "Request", "Research", "Resolve", "Respond", "Restore",
    "Restructure", "Retrieve", "Review", "Revise", "Rotate", "Sample", "Save", "Search", "Select", "Separate", "Simplify",
    "Solve", "Specify", "Stimulate", "Streamline", "Structure", "Study", "Submit", "Succeed", "Suggest", "Summarize",
    "Supervise", "Support", "Survey", "Sustain", "Test", "Trace"};
    const vector<string> negationWords = {"Not", "No", "None", "Nobody", "Nothing", "Nowhere", "Neither", "Nor", "Never", "Hardly",
    "Scarcely", "Barely", "Doesn't", "Isnt", "Wasnt", "Shouldnt", "Wouldnt", "Cant", "Wont", "Dont",
    "Arent", "Havent", "Hasnt", "Hadnt", "Couldn't", "Wouldn't", "Shouldn't", "Isn't", "Wasn't", "Won't",
    "Don't", "Aren't", "Haven't", "Hasn't", "Hadn't", "Cannot", "Can't", "Will not", "Willn't", "Wonnot",
    "Did not", "Didn't", "Does not", "Doesn't", "Do not", "Don't", "Have not", "Haven't", "Has not", "Hasn't",
    "Had not", "Hadn't", "Should not", "Shouldn't", "Would not", "Wouldn't", "Is not", "Isn't", "Was not", "Wasn't",
    "Are not", "Aren't", "Were not", "Weren't", "Cannot", "Can't", "Must not", "Mustn't", "Need not", "Needn't",
    "Shall not", "Shan't", "Will not", "Won't", "May not", "Might not", "Ought not", "Used not", "Doesn't", "Isnt",
    "Wasnt", "Shouldnt", "Wouldnt", "Cant", "Wont", "Dont", "Arent", "Havent", "Hasnt", "Hadnt", "Couldn't",
    "Wouldn't", "Shouldn't", "Isn't", "Wasn't", "Won't", "Don't", "Aren't", "Haven't", "Hasn't", "Hadn't",
    "Cannot", "Can't", "Will not", "Willn't", "Wonnot", "Did not", "Didn't", "Does not", "Doesn't", "Do not",
    "Don't", "Have not", "Haven't", "Has not", "Hasn't", "Had not", "Hadn't", "Should not", "Shouldn't", "Would not",
    "Wouldn't", "Is not", "Isn't", "Was not", "Wasn't", "Are not", "Aren't", "Were not", "Weren't", "Cannot", "Can't",
    "Must not", "Mustn't", "Need not", "Needn't", "Shall not", "Shan't", "Will not", "Won't", "May not", "Might not",
    "Ought not", "Used not"};

    // Get user input
    cout<<"Enter the text for sentiment analysis: ";
    string inputText;
    getline(cin, inputText);

    // Standardize to lowercase for consistent comparison
    transform(inputText.begin(), inputText.end(), inputText.begin(), ::tolower);

    // Tokenize input text
    istringstream iss(inputText);
    string word;

    // Initialize counters
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

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
