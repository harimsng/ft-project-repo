import os
import sys
import io

# sed is line-based replace tool.
# processing newlines is not necessary.

sedPath = '/usr/bin/sed'
myPath = './miniSed'
filePath = 'input'
sedFilePath = '.output1.temp'
myFilePath = '.output2.temp'
cpPath = '/bin/cp'
diffPath = '/usr/bin/diff'

tests = {
    1: ["1", "11111"],
    2: ["1", ""],
    3: ["123", "321"],
    4: ["123", ""],
    5: ["123", "123123123123123123"],
    6: ["123", "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"],
    7: ["12321", "abcba"],
    8: ["123123", "abcabc"],
    9: ["123123123", "abcabcabc"],
    10: ["231", "xyz"],
    11: ["312", "ijk"],
    12: ["23", "ab"],
    13: ["31", "xy"]
}

def copyFile():
    pid = os.fork()
    if pid == 0:
        arg = [cpPath, filePath, myFilePath]
        os.execve('/bin/cp', arg, os.environ)
    os.waitpid(pid, 0)

def diffFiles():
    pid = os.fork()
    if pid == 0:
        arg = [diffPath, sedFilePath, myFilePath]
        os.execve(diffPath, arg, os.environ)
    os.waitpid(pid, 0)
    
def executeSed():
    sedOutFile = open(sedFilePath, 'w')
    pid = os.fork()
    if pid == 0:
        os.dup2(sedOutFile.fileno(), sys.stdout.fileno())
        pattern = 's/' + tests[testcase][0] + '/' + tests[testcase][1] + '/g'
        arg = [sedPath, pattern, filePath]
        os.execve(sedPath, arg, os.environ)
    os.waitpid(pid, 0)
    sedOutFile.close()

def executeMinised():
    pid = os.fork()
    if pid == 0:
        arg = [myPath, myFilePath, tests[testcase][0], tests[testcase][1]]
        os.execve(myPath, arg, os.environ)
    os.waitpid(pid, 0)

def printCaseInfo(index, fromWord, toWord):
    print(f'case {index}: "{fromWord}" to "{toWord}"')

i = 0
for testcase in tests:
    i += 1
    printCaseInfo(i, tests[testcase][0], tests[testcase][1])
    copyFile()
    executeSed()
    executeMinised()
    diffFiles()
