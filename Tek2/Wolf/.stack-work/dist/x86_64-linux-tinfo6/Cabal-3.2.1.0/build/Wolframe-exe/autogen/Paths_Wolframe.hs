{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_Wolframe (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/bin"
libdir     = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/lib/x86_64-linux-ghc-8.10.7/Wolframe-0.1.0.0-Frt39Kx3guG6GzmJuUI18D-Wolframe-exe"
dynlibdir  = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/lib/x86_64-linux-ghc-8.10.7"
datadir    = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/share/x86_64-linux-ghc-8.10.7/Wolframe-0.1.0.0"
libexecdir = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/libexec/x86_64-linux-ghc-8.10.7/Wolframe-0.1.0.0"
sysconfdir = "/home/Lucas/delivery/Tek2/Wolf/.stack-work/install/x86_64-linux-tinfo6/60e60590943110d888b5abaf82c81cfb5ee7429075a95437bd7347576361d8e2/8.10.7/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "Wolframe_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "Wolframe_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "Wolframe_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "Wolframe_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "Wolframe_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "Wolframe_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
