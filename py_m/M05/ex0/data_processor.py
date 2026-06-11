#!/usr/bin/python3

import typing
import abc
from typing import Any, Union, List, Dict

class DataProcessor(abc.ABC):
    def __init__(self):
        self.stored_data = []  # Lista para armazenar os dados processados
        self.rank = 0  # Contador para o rank de processamento
    
    @abc.abstractmethod
    def validate(self, data: Any) -> bool:
        pass
    
    @abc.abstractmethod
    def ingest(self, data: Any) -> None:
        pass
    
    def output(self) -> tuple[int, str]:
        """Extrai o dado mais antigo junto com seu rank"""
        if not self.stored_data:
            return (0, "")  # Retorna vazio se não houver dados
        rank, data = self.stored_data.pop(0)
        return (rank, data)


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
    
    def validate(self, data: Any) -> bool:
        """Valida se os dados são int, float ou lista destes tipos"""
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        return False
    
    def ingest(self, data: Union[int, float, List[Union[int, float]]]) -> None:
        """Ingere dados numéricos e os converte para string"""
        if not self.validate(data):
            raise Exception("Improper numeric data")
        
        # Converte os dados para string e armazena
        if isinstance(data, (int, float)):
            self.stored_data.append((self.rank, str(data)))
            self.rank += 1
        elif isinstance(data, list):
            for item in data:
                self.stored_data.append((self.rank, str(item)))
                self.rank += 1


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
    
    def validate(self, data: Any) -> bool:
        """Valida se os dados são string ou lista de strings"""
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False
    
    def ingest(self, data: Union[str, List[str]]) -> None:
        """Ingere dados de texto e os armazena"""
        if not self.validate(data):
            raise Exception("Improper text data")
        
        if isinstance(data, str):
            self.stored_data.append((self.rank, data))
            self.rank += 1
        elif isinstance(data, list):
            for item in data:
                self.stored_data.append((self.rank, item))
                self.rank += 1


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
    
    def validate(self, data: Any) -> bool:
        """Valida se os dados são dict ou lista de dicts com chaves string"""
        if isinstance(data, dict):
            return all(isinstance(key, str) for key in data.keys())
        elif isinstance(data, list):
            return all(isinstance(item, dict) and all(isinstance(key, str) for key in item.keys()) for item in data)
        return False
    
    def ingest(self, data: Union[Dict[str, str], List[Dict[str, str]]]) -> None:
        """Ingere dados de log e os converte para formato string"""
        if not self.validate(data):
            raise Exception("Improper log data")
        
        if isinstance(data, dict):
            # Converte dict para formato "chave: valor" (exemplo específico)
            log_str = f"{data.get('log_level', 'INFO')}: {data.get('log_message', 'No message')}"
            self.stored_data.append((self.rank, log_str))
            self.rank += 1
        elif isinstance(data, list):
            for item in data:
                log_str = f"{item.get('log_level', 'INFO')}: {item.get('log_message', 'No message')}"
                self.stored_data.append((self.rank, log_str))
                self.rank += 1


def main():
    print("=== Code Nexus - Data Processor ===")
    
    # Testando NumericProcessor
    print("\nTesting Numeric Processor...")
    num_proc = NumericProcessor()
    
    print(f"Trying to validate input '42': {num_proc.validate(42)}")
    print(f"Trying to validate input 'Hello': {num_proc.validate('Hello')}")
    
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")  # Isso vai falhar
    except Exception as e:
        print(f"Got exception: {e}")
    
    print("Processing data: [1, 2, 3, 4, 5]")
    num_proc.ingest([1, 2, 3, 4, 5])
    
    print("Extracting 3 values...")
    for i in range(3):
        rank, value = num_proc.output()
        print(f"Numeric value {i}: {value}")
    
    # Testando TextProcessor
    print("\nTesting Text Processor...")
    text_proc = TextProcessor()
    
    print(f"Trying to validate input '42': {text_proc.validate(42)}")
    print("Processing data: ['Hello', 'Nexus', 'World']")
    text_proc.ingest(['Hello', 'Nexus', 'World'])
    
    print("Extracting 1 value...")
    rank, value = text_proc.output()
    print(f"Text value 0: {value}")
    
    # Testando LogProcessor
    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
    
    print(f"Trying to validate input 'Hello': {log_proc.validate('Hello')}")
    print("Processing data: [{'log_level': 'NOTICE', 'log_message': 'Connection to server'}, {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]")
    log_proc.ingest([
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ])
    
    print("Extracting 2 values...")
    for i in range(2):
        rank, value = log_proc.output()
        print(f"Log entry {i}: {value}")


if __name__ == "__main__":
    main()