fun main(args: Array<String>) {
    val readLine = readLine()
    val (N, K) = readLine?.split(' ') ?: throw IllegalArgumentException("Invalid input")

    with(PairSet(N.toInt(), K.toInt())) {
        generatePrimes()
        createPairs()
        printAnswers()
    }
}