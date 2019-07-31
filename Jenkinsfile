pipeline {
  agent {
    label 'x86&&macOS&&Apps'
  }
  environment {
    VIEW = 'lib_agc_master'
    REPO = 'lib_agc'
  }
  options {
    skipDefaultCheckout()
  }
  stages {
    stage('Get View') {
      steps {
        prepareAppsSandbox("${VIEW}", "${REPO}")
      }
    }
    stage('Library Checks') {
      steps {
        xcoreLibraryChecks("${REPO}")
      }
    }
    stage('Unit Tests') {
      steps {
        dir("${REPO}") {
          dir('tests') {
            dir('agc_unit_tests') {
              runXwaf('.')
              viewEnv() {
                runPytest()
              }
            }
          }
        }
      }
    }
    stage('Build test_wav_agc') {
      steps {
        dir("${REPO}") {
          dir('tests/test_wav_agc') {
            runXwaf('.')
          }
        }
      }
    }
    stage('Build') {
      steps {
        dir("${REPO}") {
          // xcoreAllAppsBuild('examples')
          dir("${REPO}") {
            runXdoc('doc')
          }
        }
      }
    }
  }
  post {
    success {
      updateViewfiles()
    }
    failure {
      dir("${REPO}") {
        dir('tests') {
          dir('agc_unit_tests') {
            junit 'pytest_result.xml'
          }
        }
      }
    }
    cleanup {
      cleanWs()
    }
  }
}
