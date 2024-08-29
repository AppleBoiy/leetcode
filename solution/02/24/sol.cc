struct Token {
    enum Type {
        kNumber,
        kOperator,
        kLeftParenthesis,
        kRightParenthesis,
    };

    Type type;
    int value;
    char op;

    Token(Type type, int value) : type(type), value(value) {}
    Token(Type type, char op) : type(type), op(op) {}
};


class Solution {
private:
    vector<Token> tokenize(const string& s) {
        vector<Token> tokens;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                tokens.emplace_back(Token::kNumber, num);
            } else {
                tokens.emplace_back(Token::kOperator, s[i]);
                i++;
            }
        }
        return tokens;
    }

    int evaluate(const vector<Token>& tokens, int& i) {
        int result = 0;
        int sign = 1;
        while (i < tokens.size()) {
            const Token& token = tokens[i];
            if (token.type == Token::kNumber) {
                result += sign * token.value;
            } else if (token.type == Token::kOperator) {
                if (token.op == '+') {
                    sign = 1;
                } else if (token.op == '-') {
                    sign = -1;
                } else if (token.op == '(') {
                    i++;
                    result += sign * evaluate(tokens, i);
                } else if (token.op == ')') {
                    break;
                }
            }
            i++;
        }
        return result;
    }
public:
    int calculate(string s) {
        vector<Token> tokens = tokenize(s);
        int i = 0;
        return evaluate(tokens, i);
    }
};