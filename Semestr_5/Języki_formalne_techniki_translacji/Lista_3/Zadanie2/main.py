# calclex.py

from sly import Lexer

class CalcLexer(Lexer):
    # Set of token names.   This is always required
    tokens = { NUMBER, PLUS, MINUS, TIMES, DIVIDE,
             LPAREN, RPAREN, POW}


    literals = { '(', ')', '{', '}', ';' }

    # String containing ignored characters
    ignore = ' \t'


    # Regular expression rules for tokens
    PLUS    = r'\+'
    MINUS   = r'-'
    TIMES   = r'\*'
    DIVIDE  = r'/'
    LPAREN  = r'\('
    RPAREN  = r'\)'
    POW     = r'\^'

    @_(r'\d+')
    def NUMBER(self, t):
        t.value = int(t.value)
        return t


    ignore_comment = r'\#.*'

    # Line number tracking
    @_(r'\n+')
    def ignore_newline(self, t):
        self.lineno += t.value.count('\n')

    def error(self, t):
        print('Line %d: Bad character %r' % (self.lineno, t.value[0]))
        self.index += 1

if __name__ == '__main__':
    data = '''
# Counting
x = 0;
while (x < 10) {
    print x:
    x = x + 1;
}
'''
    lexer = CalcLexer()
    for tok in lexer.tokenize(data):
        print(tok)