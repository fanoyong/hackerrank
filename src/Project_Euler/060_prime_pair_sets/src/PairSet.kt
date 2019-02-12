class PairSet constructor(private val N: Int, private val K: Int) {

    private val primes = mutableListOf(2)
    private val pairSet = mutableSetOf<Int>()

    fun generatePrimes() {
        for (i in 3..N step 2) {
            if (i.isPrime()) {
                primes.add(i)
            }
        }
    }

    fun createPairs() {
        val numList = mutableListOf<Int>()
        when (K) {
            3 -> {
                for (i in 0 until primes.size) {
                    numList.add(primes[i])
                    for (j in i + 1 until primes.size) {
                        numList.add(primes[j])
                        if (isConcatenatePrime(numList)) {
                            for (k in j + 1 until primes.size) {
                                numList.add(primes[k])
                                if (isConcatenatePrime(numList)) {
                                    pairSet.add(numList.sum())
                                }
                                numList.remove(primes[k])
                            }
                        }
                        numList.remove(primes[j])
                    }
                    numList.remove(primes[i])
                }
            }
            4 -> {
                for (i in 0 until primes.size) {
                    numList.add(primes[i])
                    for (j in i + 1 until primes.size) {
                        numList.add(primes[j])
                        if (isConcatenatePrime(numList)) {
                            for (k in j + 1 until primes.size) {
                                numList.add(primes[k])
                                if (isConcatenatePrime(numList)) {
                                    for (l in k + 1 until primes.size) {
                                        numList.add(primes[l])
                                        if (isConcatenatePrime(numList)) {
                                            pairSet.add(numList.sum())
                                        }
                                        numList.remove(primes[l])
                                    }
                                }
                                numList.remove(primes[k])
                            }
                        }
                        numList.remove(primes[j])
                    }
                    numList.remove(primes[i])
                }
            }
            5 -> {
                for (i in 0 until primes.size) {
                    numList.add(primes[i])
                    for (j in i + 1 until primes.size) {
                        numList.add(primes[j])
                        if (isConcatenatePrime(numList)) {
                            for (k in j + 1 until primes.size) {
                                numList.add(primes[k])
                                if (isConcatenatePrime(numList)) {
                                    for (l in k + 1 until primes.size) {
                                        numList.add(primes[l])
                                        if (isConcatenatePrime(numList)) {
                                            for (m in l + 1 until primes.size) {
                                                numList.add(primes[m])
                                                if (isConcatenatePrime(numList)) {
                                                    pairSet.add(numList.sum())
                                                }
                                                numList.remove(primes[m])
                                            }
                                        }
                                        numList.remove(primes[l])
                                    }
                                }
                                numList.remove(primes[k])
                            }
                        }
                        numList.remove(primes[j])
                    }
                    numList.remove(primes[i])
                }
            }
            else -> IllegalArgumentException("Invalid input")
        }
    }

    private fun isConcatenatePrime(nums: List<Int>): Boolean {
        for (i in 0 until nums.size) {
            for (j in i + 1 until nums.size) {
                if (!isConcatenatePrime(nums[i], nums[j])) {
                    return false
                }
            }
        }
        return true
    }

    fun printAnswers() {
        pairSet.forEach {
            System.out.println(it)
        }
    }

    private fun isConcatenatePrime(a: Int, b: Int) = concatenate(a, b).isPrime() && concatenate(b, a).isPrime()

    private fun concatenate(a: Int, b: Int) =
        (a.toString() + b.toString()).toInt()

    private fun Int.isPrime(): Boolean {
        if (this <= 1) return false
        for (i in 2 until Math.sqrt(this.toDouble()).toInt() + 1)
            if (this.rem(i) == 0)
                return false

        return true
    }
}