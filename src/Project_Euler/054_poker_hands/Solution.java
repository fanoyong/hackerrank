import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    public enum LEVEL {
        TWO(1), THREE(2), FOUR(3), FIVE(4), SIX(5), SEVEN(6), EIGHT(7), NINE(8), TEN(9), JACK(10), QUEEN(11), KING(12), ACE(13);

        private final int level;

        private LEVEL(int level) {
            this.level = level;
        }
    }

    public enum TYPE {
        CLOVER(1), HEART(2), DIAMOND(3), SPADE(4);

        private final int level;

        private TYPE(int level) {
            this.level = level;
        }
    }

    private static class Card {

        public LEVEL mLevel;
        public TYPE mType;

        public Card(LEVEL level, TYPE type) {
            mLevel = level;
            mType = type;
        }
    }

    private static class Player {

        private ArrayList<Card> mInHands = new ArrayList<Card>();

        private boolean mIsFlush = false;
        private boolean mIsRoyal = false;

        public void addCard(Card card) {
            mInHands.add(card);
        }

        /**
         * Borrowed idea from Nayuki.io
         * https://github.com/nayuki/Project-Euler-solutions/blob/master/java/p054.java
         */
        public int checkPower() {
            int[] countByCard = new int[13];
            mIsFlush = true;
            TYPE flushCheck = mInHands.get(0).mType;
            for (Card card : mInHands) {
                countByCard[card.mLevel.level - 1]++;
                if (card.mType != flushCheck) {
                    mIsFlush = false;
                }
            }
            int[] countByLevel = new int[6];
            for (int count : countByCard) {
                countByLevel[count]++;
            }
            int bestCards = get5FrequentHighestCards(countByCard, countByLevel);
            int straightHighRank = getStraightHighRank(countByCard);
            mIsRoyal = (countByCard[12] != 0) && (countByCard[11] != 0) && (countByCard[10] != 0) && (countByCard[9] != 0) && (countByCard[8] != 0);

            if (mIsFlush && mIsRoyal)
                return 9 << 20 | bestCards; // Royal flush
            else if (straightHighRank != -1 && mIsFlush)
                return 8 << 20 | straightHighRank; // Straight flush
            else if (countByLevel[4] == 1)
                return 7 << 20 | bestCards; // Four of a kind
            else if (countByLevel[3] == 1 && countByLevel[2] == 1)
                return 6 << 20 | bestCards; // Full house
            else if (mIsFlush)
                return 5 << 20 | bestCards; // Flush
            else if (straightHighRank != -1)
                return 4 << 20 | straightHighRank; // Straight
            else if (countByLevel[3] == 1)
                return 3 << 20 | bestCards; // Three of a kind
            else if (countByLevel[2] == 2)
                return 2 << 20 | bestCards; // Two pairs
            else if (countByLevel[2] == 1)
                return 1 << 20 | bestCards; // One pair
            else
                return 0 << 20 | bestCards;
        }

        private static int get5FrequentHighestCards(int[] ranks, int[] ranksHist) {
            int result = 0;
            int count = 0;
            for (int i = ranksHist.length - 1; i >= 0; i--) {
                for (int j = ranks.length - 1; j >= 0; j--) {
                    if (ranks[j] == i) {
                        for (int k = 0; k < i && count < 5; k++, count++)
                            result = result << 4 | j;
                    }
                }
            }
            return result;
        }

        private static int getStraightHighRank(int[] ranks) {
            outer: for (int i = ranks.length - 1; i >= 3; i--) {
                for (int j = 0; j < 5; j++) {
                    if (ranks[(i - j + 13) % 13] == 0)
                        continue outer; // Current offset is not a straight
                }
                return i; // Straight found
            }
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            Player p1 = new Player();
            for (int i = 0; i < 5; i++) {
                String input = scanner.next();
                TYPE type = getType(input);
                LEVEL level = getLevel(input);
                Card card = new Card(level, type);
                p1.addCard(card);
            }
            Player p2 = new Player();
            for (int i = 0; i < 5; i++) {
                String input = scanner.next();
                TYPE type = getType(input);
                LEVEL level = getLevel(input);
                Card card = new Card(level, type);
                p2.addCard(card);
            }
            if (p1.checkPower() < p2.checkPower()) {
                System.out.println("Player 2");
            } else {
                System.out.println("Player 1");
            }
        }
        scanner.close();
    }

    private static TYPE getType(String input) {
        TYPE type;
        char c = input.charAt(1);
        switch (c) {
            case 'S':
            case 's':
                type = TYPE.SPADE;
                break;
            case 'D':
            case 'd':
                type = TYPE.DIAMOND;
                break;
            case 'H':
            case 'h':
                type = TYPE.HEART;
                break;
            case 'C':
            case 'c':
            default:
                type = TYPE.CLOVER;
                break;
        }
        return type;
    }

    private static LEVEL getLevel(String input) {
        LEVEL level;
        char lc = input.charAt(0);
        switch (lc) {
            case '2':
                level = LEVEL.TWO;
                break;
            case '3':
                level = LEVEL.THREE;
                break;
            case '4':
                level = LEVEL.FOUR;
                break;
            case '5':
                level = LEVEL.FIVE;
                break;
            case '6':
                level = LEVEL.SIX;
                break;
            case '7':
                level = LEVEL.SEVEN;
                break;
            case '8':
                level = LEVEL.EIGHT;
                break;
            case '9':
                level = LEVEL.NINE;
                break;
            case 'T':
            case 't':
                level = LEVEL.TEN;
                break;
            case 'J':
            case 'j':
                level = LEVEL.JACK;
                break;
            case 'Q':
            case 'q':
                level = LEVEL.QUEEN;
                break;
            case 'K':
            case 'k':
                level = LEVEL.KING;
                break;
            case 'A':
            case 'a':
            default:
                level = LEVEL.ACE;
                break;
        }
        return level;
    }
}

