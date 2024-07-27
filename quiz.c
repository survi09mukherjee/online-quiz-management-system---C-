#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Question {
public:
    string text;
    vector<string> options;
    int answerIndex;

    Question(string text, const vector<string>& options, int answerIndex) :
        text(text), options(options), answerIndex(answerIndex) {}

    bool isCorrect(int userAnswer) const {
        return userAnswer == answerIndex;
    }
};

class Quiz {
public:
    vector<Question> questions;
    int score;
    time_t startTime;

    Quiz(const vector<Question>& questions) : questions(questions), score(0) {
        startTime = time(0);
    }

    void takeQuiz() {
        for (const Question& question : questions) {
            cout << question.text << endl;
            for (int i = 0; i < question.options.size(); ++i) {
                cout << "\t" << i + 1 << ". " << question.options[i] << endl;
            }

            int answer;
            cin >> answer;

            if (question.isCorrect(answer - 1)) {
                score++;
            }
        }
    }

    int calculateScore() {
        time_t endTime = time(0);
        int elapsedTime = difftime(endTime, startTime); // Time spent in seconds
        return score * (100 / max(elapsedTime, 1)); // Normalize score based on time
    }
};

int main() {
    // Sample questions (replace with actual question data)
    vector<Question> questions = {
        Question("What is the capital of France?", {"Paris", "London", "Berlin"}, 0),
        // ... more questions
    };

    Quiz quiz(questions);
    quiz.takeQuiz();

    int finalScore = quiz.calculateScore();
    cout << "Your score: " << finalScore << endl;

    // (Optional) Persist score to a leaderboard using a database or file
}
