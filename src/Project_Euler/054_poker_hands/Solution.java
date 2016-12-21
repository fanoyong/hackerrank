import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution {

    public enum POWER {
        NOTHING(0), HIGH_CARD(1), ONE_PAIR(2), TWO_PAIRS(3), THREE_OF_A_KIND(4), STRAIGHT(5), FLUSH(6), FULL_HOUSE(7), FOUR_OF_A_KIND(8), STRAIGHT_FLUSH(
                9), ROYAL_FLUSH(10);

        public final int level;

        POWER(int level) {
            this.level = level;
        }
    }

    public enum Type {
        SPADE(4), DIAMOND(3), HEART(2), CLOVER(1);
        public final int level;

        Type(int level) {
            this.level = level;
        }
    }

    private static class Card {
        public int mNumber;
        public Type mType;

        public Card(String card) {
            char c1 = card.charAt(0);
            switch (c1) {
                case '1':
                    mNumber = 1;
                    break;
                case '2':
                    mNumber = 2;
                    break;
                case '3':
                    mNumber = 3;
                    break;
                case '4':
                    mNumber = 4;
                    break;
                case '5':
                    mNumber = 5;
                    break;
                case '6':
                    mNumber = 6;
                    break;
                case '7':
                    mNumber = 7;
                    break;
                case '8':
                    mNumber = 8;
                    break;
                case '9':
                    mNumber = 9;
                    break;
                case 'J':
                case 'j':
                    mNumber = 10;
                    break;
                case 'Q':
                case 'q':
                    mNumber = 11;
                    break;
                case 'K':
                case 'k':
                    mNumber = 12;
                    break;
                case 'A':
                case 'a':
                    mNumber = 13;
            }
            char c2 = card.charAt(1);
            switch (c2) {
                case 'S':
                case 's':
                    mType = Type.SPADE;
                    break;
                case 'D':
                case 'd':
                    mType = Type.DIAMOND;
                    break;
                case 'H':
                case 'h':
                    mType = Type.HEART;
                    break;
                case 'C':
                case 'c':
                    mType = Type.CLOVER;
                    break;
            }
        }
    }

    private static class InHand implements Comparable<InHand> {

        private ArrayList<Card> mCards;
        private POWER mPower;
        private POWER mSecond;
        private Type mRepresentType;

        private boolean isRoyal = false;
        private boolean isFlush = false;
        private boolean isStraight = false;
        private boolean isFourOfAkind = false;
        private boolean isThreeOfAKind = false;
        private boolean isTwoPairs = false;
        private boolean isOnePair = false;

        public InHand(String c1, String c2, String c3, String c4, String c5) {
            Card card1 = new Card(c1);
            Card card2 = new Card(c2);
            Card card3 = new Card(c3);
            Card card4 = new Card(c4);
            Card card5 = new Card(c5);
            mCards.add(card1);
            mCards.add(card2);
            mCards.add(card3);
            mCards.add(card4);
            mCards.add(card5);
            Collections.sort(mCards);
            if (checkRoyalFlush()) {
                return;
            }
            if (checkStraightFlush()) {
                return;
            }
            if (checkFourOfAKind()) {
                return;
            }
            if (checkFlush()) {
                return;
            }
            if (checkStraight()) {
                return;
            }
            if (checkThreeOfAKind()) {
                return;
            }
            if (checkTwoPairs()) {
                return;
            }
            if (checkOnePair()) {
                return;
            }
        }

        private boolean checkOnePair() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkTwoPairs() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkThreeOfAKind() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkStraight() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkFlush() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkFourOfAKind() {
            // TODO Auto-generated method stubm
            return false;
        }

        private boolean checkStraightFlush() {
            // TODO Auto-generated method stub
            return false;
        }

        private boolean checkRoyalFlush() {
            Card firstCard = mCards.get(0);
            Type type = mCards.get(0)
            for(int i=1;i<5;i++) {
                
                
            }
            
            
            this.mPower = POWER.ROYAL_FLUSH;
            return true;
        }

        @Override
        public int compareTo(InHand target) {
            if (this.mPower.level < target.mPower.level) {
                return -1;
            } else if (this.mPower.level > target.mPower.level) {
                return 1;
            }
            if (this.mSecond.level < target.mSecond.level) {
                return -1;
            } else if (this.mSecond.level > target.mSecond.level) {
                return 1;
            }
            return this.mRepresentType.level < target.mRepresentType.level ? -1 : 1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            String s1 = scanner.next();
            String s2 = scanner.next();
            String s3 = scanner.next();
            String s4 = scanner.next();
            String s5 = scanner.next();
            InHand ih1 = new InHand(s1, s2, s3, s4, s5);
            s1 = scanner.next();
            s2 = scanner.next();
            s3 = scanner.next();
            s4 = scanner.next();
            s5 = scanner.next();
            InHand ih2 = new InHand(s1, s2, s3, s4, s5);
            if (ih1.compareTo(ih2) < 0) {
                System.out.println("Player 2");
            } else {
                System.out.println("Player 1");
            }
        }
        scanner.close();
    }

}

